/* Collects up to max grid objects whose box passes the three cross-product tests against the segment from -> to,
 * writes them to out and returns how many were written. Unless flag is set, func_0204f9bc first probes the
 * segment, and when its result distance is below PROBE_LIMIT the end point is replaced by the one func_0204f7dc
 * computes. The segment is kept as a midpoint plus a half vector. The grid iterator (func_020555c4 sets its row
 * and column range from the box around the segment) visits each cell's object list.
 *
 * An object is tested once per call: its stamp is set to data_021019d8, which is incremented here. Callers set an
 * object's stamp to data_021019d8 + 1 beforehand to exclude it (func_020451dc, func_0202d444, func_0202e434).
 * mask selects object type bits. */
#include "m2c.h"

enum {
    PROBE_LIMIT  = 0x2000,
    FILTER_MASK  = 0x200803, /* object flag bits that are compared */
    FILTER_VALUE = 1,        /* required value of those bits */
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    void *obj;
    s32 dist;
} Hit;

typedef struct {
    s32 w[4];
} Rot;

typedef struct {
    s32 w[6];
} Box;

typedef struct {
    s32 w[6]; /* grid, row, column, first row, last row, last column */
} Iter;

typedef struct {
    u8 pad0[4];
    Vec3 pos;
    u8 pad10[0x15];
    s8 kind;
    u8 pad26[2];
    Vec3 size;
} Shape;

typedef struct {
    u8 pad0[8];
    u32 flags;
    u16 types; /* bits selected by the mask argument */
    u8 pade[0x12];
    Shape *shape;
    u8 pad24[4];
    s32 stamp; /* data_021019d8 of the last call that tested it */
} Obj;

typedef struct Link {
    Obj *obj;
    struct Link *next;
} Link;

extern s32 data_021019d8;
extern u8 data_0210930c[];
extern u8 data_021094ac[];

extern void func_02007f24(Fx *out, f64 d);
extern void func_0200af6c(Fx *out, const s32 *x);
extern s32 *func_0204c5fc(Box *box, Vec3 *center, Vec3 *ext);
extern void func_0204c7b0(Rot *dest, void *src);
extern void func_0204f7dc(Vec3 *out, Vec3 *from, Vec3 *dir, Rot *rot, s32 arg4);
extern void func_0204f9bc(Hit *out, void *world, Vec3 *from, Vec3 *to, s32 arg4);
extern void *func_020555c4(Iter *it, void *grid, Box *box);
extern void func_02055630(Iter *it);
extern Link *func_02055660(const Iter *it);
extern s32 func_02055684(Iter *it);
extern s32 FX_Div(s32, s32);

static inline void vec_make(Vec3 *v, s32 x, s32 y, s32 z) {
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

static inline void vec_mid(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s32 x = a->x + b->x;
    s32 z = a->z + b->z;
    s32 y = a->y + b->y;
    d->x  = x >> 1;
    d->y  = y >> 1;
    d->z  = z >> 1;
}

static inline void vec_sub(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s32 x = a->x - b->x;
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline Vec3 *shape_size(Shape *sh) {
    return &sh->size;
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline s32 fx_val(const Fx *r) {
    const Fx *p = r;

    if (!p) { // FAKE: always-false null test keeps the add rX,sp / ldr form
        p = NULL;
    }
    return p->v;
}

/* |*x| + m; func_0200af6c stores the absolute value through its first argument */
static inline s32 fx_abs_add(const s32 *x, s32 m) {
    Fx r;
    s32 v;

    func_0200af6c(&r, x);
    v = fx_val(&r);
    return v + m;
}

static inline s32 fx_abs(s32 v) {
    s32 x = v;
    Fx r;
    func_0200af6c(&r, &x);
    return fx_val(&r);
}

s32 func_0200a6c4(Vec3 *from, Vec3 *to, Obj **out, u32 max, s32 mask, u8 flag) {
    s32 dy;
    s32 dz;
    u32 count;
    Link *n;
    s32 dx;
    s32 c;
    s32 lim;
    s32 margin;
    Obj *o;
    Shape *s;
    Vec3 e;
    Vec3 end;
    Vec3 dir;
    Vec3 mid;
    Vec3 half;
    Vec3 ext;
    Box box;
    Vec3 size;
    Iter it;
    Vec3 hit;
    Rot rot;
    Vec3 cyl;
    Hit res;
    Fx ax;
    Fx ay;
    Fx az;
    Fx one;

    end.x = to->x;
    end.y = to->y;
    end.z = to->z;
    if (!flag) {
        func_0204f9bc(&res, *(void **) (*(u8 **) (data_0210930c + 0x68) + 0x384), from, to, 0);
        if (res.dist < PROBE_LIMIT) {
            vec_sub(&dir, to, from);
            func_0204c7b0(&rot, res.obj);
            func_0204f7dc(&hit, from, &dir, &rot, 0);
            vec_set(&end, &hit);
        }
    }
    vec_mid(&mid, from, &end);
    vec_sub(&half, &mid, from);
    func_0200af6c(&az, &half.z);
    func_0200af6c(&ay, &half.y);
    func_0200af6c(&ax, &half.x);
    vec_make(&ext, ax.v, ay.v, az.v);
    func_0204c5fc(&box, &mid, &ext);
    func_02007f24(&one, 1.0);
    /* |half| plus a small margin, used in the cross-product limits below */
    margin = FX_Div(fx_val(&one), 0x80000);
    vec_make(&e, fx_abs_add(&half.x, margin), fx_abs_add(&half.y, margin), fx_abs_add(&half.z, margin));
    count = 0;
    vec_make(&size, 0, 0, 0);
    data_021019d8++; /* new stamp: no object has been tested in this call yet */
    func_020555c4(&it, data_021094ac, &box);
    while (!func_02055684(&it)) {
        for (n = func_02055660(&it); n != NULL; n = n->next) {
            o = n->obj;
            if (!(mask & o->types)) {
                continue;
            }
            if ((o->flags & FILTER_MASK) != FILTER_VALUE) {
                continue;
            }
            if (o->stamp == data_021019d8) {
                continue;
            }
            o->stamp = data_021019d8;
            s        = o->shape;
            if (s == NULL) {
                continue;
            }
            if (s->kind != 3) {
                if (s->kind != 5) {
                    continue;
                }
                vec_set(&size, shape_size(s));
            } else {
                vec_make(&cyl, s->size.y, s->size.x, s->size.y);
                vec_set(&size, &cyl);
            }
            /* separating-axis test: cross products of the segment direction with the x, y and z axes */
            dz = mid.z;
            dz -= s->pos.z;
            dy = mid.y;
            dy -= s->pos.y;
            dx  = mid.x - s->pos.x;
            lim = fx_mul(size.y, e.z) + fx_mul(size.z, e.y);
            c   = fx_mul(dy, half.z) - fx_mul(dz, half.y);
            if (fx_abs(c) > lim) {
                continue;
            }
            lim = fx_mul(size.z, e.x) + fx_mul(size.x, e.z);
            c   = fx_mul(dz, half.x) - fx_mul(dx, half.z);
            if (fx_abs(c) > lim) {
                continue;
            }
            c   = fx_mul(dx, half.y) - fx_mul(dy, half.x);
            lim = fx_mul(size.x, e.y) + fx_mul(size.y, e.x);
            if (fx_abs(c) > lim) {
                continue;
            }
            out[count] = o;
            count++;
            if (count >= max) {
                break;
            }
        }
        func_02055630(&it);
    }
    return count;
}
