#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    void *vptr;
    Vec3 center;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    Vec3 extent;
} Box;

enum {
    FX_ONE = 0x1000
};

extern s32 FX_Div(s32 num, s32 den);
void func_0200ad80(Vec3 *arg0, const Vec3 *arg1);

static inline void vec_add(const Vec3 *a, const Vec3 *b, Vec3 *d) {
    s32 z = a->z + b->z;
    s32 y = a->y + b->y;
    s32 x = a->x + b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void vec_sub(const Vec3 *a, const Vec3 *b, Vec3 *d) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void vec_set(Vec3 *d, s32 x, s32 y, s32 z) {
    d->x = x;
    d->y = y;
    d->z = z;
}

static inline void vec_neg(const Vec3 *a, Vec3 *d) {
    const s32 *p = (const s32 *) a;
    vec_set(d, -p[0], -p[1], -p[2]);
}

static inline void vec_copy(const Vec3 *a, Vec3 *d) {
    if (d != a) {
        d->x = a->x;
        d->y = a->y;
        d->z = a->z;
    }
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void miss_normal(Vec3 *out, const Vec3 *dir) {
    Vec3 n;
    func_0200ad80(&n, dir);
    vec_neg(&n, out);
}

void func_02009770(Vec3 *out, Vec3 *origin, Vec3 *dir, Box *box) {
    Vec3 minB;
    Vec3 maxB;
    Vec3 maxT;
    Vec3 coord;
    s32 bad;
    u8 inside;
    int which;
    s32 i;

    s32 *a;
    s32 *o;
    s32 *c;
    s32 *b;
    s32 *tt;
    s32 *mx;

    vec_sub(&box->center, &box->extent, &minB);
    vec_add(&box->center, &box->extent, &maxB);
    vec_set(&maxT, -FX_ONE, -FX_ONE, -FX_ONE);
    vec_set(&coord, 0, 0, 0);
    inside = 1;
    i      = 0;
    a      = (s32 *) &minB;
    o      = (s32 *) origin;
    c      = (s32 *) &coord;
    b      = (s32 *) dir;
    tt     = (s32 *) &maxT;
    mx     = (s32 *) &maxB;
    for (; i < 3; i++) {
        if (*o < *a) {
            *c     = *a;
            inside = 0;
            if (*b != 0) {
                *tt = FX_Div(*a - *o, *b);
            }
        } else if (*o > *mx) {
            *c     = *mx;
            inside = 0;
            if (*b != 0) {
                *tt = FX_Div(*mx - *o, *b);
            }
        }
        a++;
        o++;
        c++;
        b++;
        tt++;
        mx++;
    }

    if (inside) {
        vec_copy(origin, &coord);
        miss_normal(out, dir);
        return;
    }

    which = 0;
    if (maxT.y > maxT.x) {
        which = 1;
    }
    if (maxT.z > (&maxT.x)[which]) {
        which = 2;
    }
    tt = (s32 *) &maxT;

    bad = tt[which] < 0 || tt[which] > FX_ONE;
    if (bad) {
        miss_normal(out, dir);
        return;
    }

    // Second pass reuses the walkers: a now walks dir and b walks minB.
    o  = (s32 *) origin;
    c  = (s32 *) &coord;
    b  = (s32 *) &minB;
    a  = (s32 *) dir;
    mx = (s32 *) &maxB;
    for (i = 0; i < 3; i++) {
        if (i != which) {
            int p = fx_mul(tt[which], *a);
            p     = *o + p;
            *c    = p;
            if (*c < *b || *c > *mx) {
                miss_normal(out, dir);
                return;
            }
        }
        a++;
        o++;
        c++;
        b++;
        mx++;
    }

    switch (which) {
        case 0:
            if (dir->x > 0) {
                vec_set(out, -FX_ONE, 0, 0);
                return;
            }
            vec_set(out, FX_ONE, 0, 0);
            return;
        case 1:
            if (dir->y > 0) {
                vec_set(out, 0, -FX_ONE, 0);
                return;
            }
            vec_set(out, 0, FX_ONE, 0);
            return;
        case 2:
            if (dir->z > 0) {
                vec_set(out, 0, 0, -FX_ONE);
                return;
            }
            vec_set(out, 0, 0, FX_ONE);
            return;
        default:
            miss_normal(out, dir);
            return;
    }
}
