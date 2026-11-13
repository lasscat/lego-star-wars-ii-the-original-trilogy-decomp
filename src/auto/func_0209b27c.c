#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Tri;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    s32 v;
} Fx;

extern const s16 data_020f88c4[]; /* interleaved {sin, cos} table, 20.12 */
extern Tri data_020ff9b4;
extern u8 data_021027f8[];
extern void *data_02109358[];
extern s32 data_027e02a4;

void func_02001688(s32);
void func_020016c0(void);
void func_02007f24(s32 *, f64); /* *out = (s32) (d * 4096.0): double to 20.12 */
void func_0201b318(void *, u8);
s32 FX_Div(s32, s32);

static inline void tri_set(Tri *d, const Tri *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void tri_sub(Tri *out, const Tri *a, const Tri *b) {
    Tri t;
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    t.x   = x;
    t.y   = y;
    t.z   = z;
    tri_set(out, &t);
}

/* Rotates (x, z) of v about the Y axis by -a using the sin/cos table, 20.12 rounding. */
static inline void tri_roty(Tri *v, Ang a) {
    s32 s = data_020f88c4[((u16) -a.v >> 4) * 2];
    s32 c = data_020f88c4[((u16) -a.v >> 4) * 2 + 1];
    s32 x = v->x;
    s32 z = v->z;
    s32 nx;
    s32 t;
    t  = (s32) (((s64) z * s + 0x800) >> 12);
    nx = (s32) (((s64) x * c + 0x800) >> 12);
    nx += t;
    v->x = nx;
    t    = (s32) (((s64) x * s + 0x800) >> 12);
    t    = (s32) (((s64) z * c + 0x800) >> 12) - t;
    v->z = t;
}

static inline s32 fx_mul(s32 a, Fx b) {
    return (s32) (((s64) a * b.v + 0x800) >> 12);
}

static inline void tri_scale_x(Tri *v, const Fx *s) {
    v->x = fx_mul(v->x, *s);
}

static inline void tri_scale_xy(Tri *v, const Fx *s) {
    tri_scale_x(v, s);
    v->y = fx_mul(v->y, *s);
}

static inline void tri_scale(Tri *v, const Fx *s) {
    tri_scale_xy(v, s);
    v->z = fx_mul(v->z, *s);
}

static inline void toggle(s32 *p) {
    *p = !*p;
}

static inline s32 fx_from(f64 d) {
    s32 t;
    func_02007f24(&t, d);
    return t;
}

enum {
    CENTRE_X = 0xac000,
    CENTRE_Z = 0x4c000,
    SPAN_X   = 0x88000,
    SPAN_Z   = 0x78000,
    DY_STEP  = 0x32000
};

/*
 * Called by func_0209b0b8 with a position triple (ref) and a per-slot target
 * object.  Takes the scene object picked by the byte at data_021027f8 + 0x2a,
 * forms its 0xb0 position minus ref, rotates that about Y by minus the angle
 * at obj + 0xca, scales it by 0.25 and offsets it by (CENTRE_X, CENTRE_Z).
 * If the point lies within half of (SPAN_X, SPAN_Z) of that centre, bit 0 of
 * target + 8 is set, the point is stored at target + 0x4c / + 0x50 and
 * 4 - (dy / DY_STEP) clamped to [0, 8] goes to func_0201b318; otherwise bit 0
 * is cleared.  data_027e02a4 is toggled before and after.
 */
void func_0209b27c(void *arg0, Tri *ref, void *target) {
    Tri v;
    s32 px;
    s32 py;
    s32 pz;
    void *obj;
    s32 vis;
    Fx scale;
    s8 level;
    s32 sx;
    s32 sz;

    func_02001688(0);
    obj = data_02109358[data_021027f8[0x2a]];
    px  = M2C_FIELD(obj, s32 *, 0xb0);
    py  = M2C_FIELD(obj, s32 *, 0xb4);
    pz  = M2C_FIELD(obj, s32 *, 0xb8);
    v.x = 0;
    v.y = 0;
    v.z = 0;
    tri_set(&v, &data_020ff9b4);
    vis = 1;
    {
        Tri t;
        s32 z = pz - ref->z;
        s32 y = py - ref->y;
        s32 x = px - ref->x;
        t.x   = x;
        t.y   = y;
        t.z   = z;
        tri_set(&v, &t);
    }
    tri_roty(&v, *(Ang *) ((s8 *) obj + 0xca));

    func_02007f24(&scale.v, 0.25);
    tri_scale(&v, &scale);
    sx = v.x + CENTRE_X;
    sz = v.z + CENTRE_Z;

    if (sx < CENTRE_X - (s32) (((s64) fx_from(0.5) * SPAN_X + 0x800) >> 12)) {
        vis = 0;
    } else if (sz < CENTRE_Z - (s32) (((s64) fx_from(0.5) * SPAN_Z + 0x800) >> 12)) {
        vis = 0;
    } else if (sx > CENTRE_X + (s32) (((s64) fx_from(0.5) * SPAN_X + 0x800) >> 12)) {
        vis = 0;
    } else if (sz > CENTRE_Z + (s32) (((s64) fx_from(0.5) * SPAN_Z + 0x800) >> 12)) {
        vis = 0;
    }

    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    if (vis) {
        M2C_FIELD(target, u32 *, 8) |= 1;
        M2C_FIELD(target, s32 *, 0x4c) = sx;
        M2C_FIELD(target, s32 *, 0x50) = sz;
        level                          = 4;
        level -= FX_Div(M2C_FIELD(obj, s32 *, 0xb4) - ref->y, DY_STEP) >> 12;
        if (level <= 0) {
            level = 0;
        }
        if (level >= 8) {
            level = 8;
        }
        func_0201b318(target, level);
    } else {
        M2C_FIELD(target, u32 *, 8) &= ~1;
    }
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_020016c0();
}
