#include "m2c.h"

/* func_020a5234 - reads the entry selected by obj->f293 from the list at
 * obj->f21c (func_02067b48): a position in whole units and three Q12
 * fixed-point radian angles. The position is widened to 20.12 fixed point and
 * the angles are converted to 16-bit angles; both go through func_020a9484, and
 * its results are stored into obj->pos (sets f49) and obj->ang0..2 (sets f48)
 * when they changed.
 */

enum {
    FX_SHIFT = 12, /* whole units -> 20.12 fixed point */
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    Ang x;
    Ang y;
    Ang z;
} Rot;

typedef struct {
    s16 px;
    s16 py;
    s16 pz;
    s16 rz;
    s16 ry;
    s16 rx;
} Entry;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x40 - 0x34];
    u16 ang0;
    u16 ang1;
    u16 ang2;
    u8 pad2[0x48 - 0x46];
    u8 f48;
    u8 f49;
    u8 pad3[0x21c - 0x4a];
    void *f21c;
    u8 pad4[0x293 - 0x220];
    u8 f293;
} Obj;

Entry *func_02067b48(void *table, u8 index);
void func_020a9484(Obj *obj, Vec3 *in, Ang a, Ang b, Ang c, Vec3 *out, u16 *p1, u16 *p2, u16 *p3);

static inline void vec_init(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

/* Q12 radians -> 16-bit angle: rad * 65536 / (2 * pi * 4096), rounded
 * (0x28BE60DB9391 / 2^44). The result goes back into rad: a separate result
 * local colours the first conversion's registers differently. */
static inline Ang rad_to_angle(s32 rad, Ang *a) {
    rad  = (s32) (((s64) rad * 0x28BE60DB9391LL + 0x80000000000LL) >> 44);
    a->v = rad;
    return *a;
}

static inline void set_ang(Obj *o, u16 *d, Ang a) {
    if (*d != a.v) {
        *d     = a.v;
        o->f48 = 1;
    }
}

void func_020a5234(Obj *obj) {
    Entry *e;
    Vec3 in;
    Vec3 np;
    Rot rot;
    Rot out;
    Rot conv;
    Rot r;

    e = func_02067b48(obj->f21c, obj->f293);
    vec_init(&in, e->px << FX_SHIFT, e->py << FX_SHIFT, e->pz << FX_SHIFT);
    r.z = rad_to_angle(e->rz, &conv.z);
    r.y = rad_to_angle(e->ry, &conv.y);
    r.x = rad_to_angle(e->rx, &conv.x);
    rot = r;
    vec_init(&np, 0, 0, 0);
    func_020a9484(obj, &in, rot.y, rot.z, rot.x, &np, &out.y.v, &out.z.v, &out.x.v);
    if (vec_ne(&obj->pos, &np)) {
        vec_set(&obj->pos, &np);
        obj->f49 = 1;
    }
    set_ang(obj, &obj->ang0, out.y);
    set_ang(obj, &obj->ang1, out.z);
    set_ang(obj, &obj->ang2, out.x);
}
