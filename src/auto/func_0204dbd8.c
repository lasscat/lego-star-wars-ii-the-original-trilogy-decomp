#include "m2c.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

enum {
    FX_FRAC_BITS = 12
};   /* 20.12 fixed point */
enum {
    FX_HALF = 0x800
};     /* one half, added before the shift to round */

/* Hardware divider and square-root unit registers. */
enum {
    REG_DIVCNT = 0x04000280
};
enum {
    REG_DIV_NUMER = 0x04000290
};
enum {
    REG_DIV_DENOM = 0x04000298
};
enum {
    REG_DIV_RESULT = 0x040002A0
};
enum {
    REG_SQRTCNT = 0x040002B0
};
enum {
    REG_SQRT_RESULT = 0x040002B4
};
enum {
    REG_SQRT_PARAM = 0x040002B8
};
enum {
    HW_BUSY = 0x8000
};    /* DIVCNT/SQRTCNT busy bit */

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;

/* Contact query result filled by func_01ffa338. */
typedef struct {
    s32 id;
    Vec normal;
    s32 dist;
    s32 f14;
    s32 f18;
} Hit;

typedef struct {
    s32 id;
    Vec normal;
} Plane;

typedef struct {
    Vec pos;
    s32 f0c;
    s32 f10;
    s32 count;
    Plane planes[3];
} Result;

typedef struct {
    u8 pad[0x60];
    Vec f60;
} Body;

extern Vec data_020ff9b4;
extern s32 data_020fe498[];

extern void func_01ffa338(Body *, void *, void *, Vec *, void *, Hit *);
extern void func_02039eec(Vec *, Vec *, Vec *);

static inline void VecCopy(Vec *dst, Vec *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

static inline s32 VecIsZero(Vec *v) {
    return v->x == 0 && v->y == 0 && v->z == 0;
}

static inline s32 FxMul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_FRAC_BITS);
}

static inline s32 VecDot(Vec *a, Vec *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + FX_HALF) >> FX_FRAC_BITS);
}

static inline void HitInit(Hit *h) {
    h->id       = 0;
    h->normal.x = 0;
    h->normal.y = 0;
    h->normal.z = 0;
    h->dist     = 0x2000;
    h->f14      = 0;
    h->f18      = 0;
}

static inline void PlaneSet(Plane *p, Hit *h) {
    p->id = h->id;
    VecCopy(&p->normal, &h->normal);
}

static inline void VecAdd(Vec *dst, Vec *a, const Vec *b) {
    dst->x = a->x + b->x;
    dst->y = a->y + b->y;
    dst->z = a->z + b->z;
}

static inline void Project(Vec *out, Vec *p, Vec *n) {
    if (VecIsZero(p)) {
        out->x = data_020ff9b4.x;
        out->y = data_020ff9b4.y;
        out->z = data_020ff9b4.z;
    } else {
        s32 k;
        k = data_020fe498[1] - VecDot(p, n);
        /* out = p + n * k: scale into out, then add p */
        out->z = FxMul(n->z, k);
        out->y = FxMul(n->y, k);
        out->x = FxMul(n->x, k);
        VecAdd(out, p, out);
    }
}

/* dst = src / |src| in 20.12: (1 << 56) / |src|^2 from the divider times sqrt(4 |src|^2) from the root unit. */
static inline void VecNormalizeFx(const Vec *src, Vec *dst) {
    s64 t;
    s64 div;
    s32 sqrt;

    t = (s64) src->x * src->x;
    t += (s64) src->y * src->y;
    t += (s64) src->z * src->z;

    (*(vu16 *) REG_DIVCNT)    = 2;
    (*(vu64 *) REG_DIV_NUMER) = 1LL << 56;
    (*(vu64 *) REG_DIV_DENOM) = t;
    (*(vu16 *) REG_SQRTCNT)   = 1;
    (*(u64 *) REG_SQRT_PARAM) = t << 2;

    while ((*(vu16 *) REG_SQRTCNT) & HW_BUSY) {
    }
    sqrt = (s32) (*(vu32 *) REG_SQRT_RESULT);

    while ((*(vu16 *) REG_DIVCNT) & HW_BUSY) {
    }
    div = (s64) (*(u64 *) REG_DIV_RESULT);
    div *= sqrt;

    dst->x = (s32) ((div * src->x + (1LL << 44)) >> 45);
    dst->y = (s32) ((div * src->y + (1LL << 44)) >> 45);
    dst->z = (s32) ((div * src->z + (1LL << 44)) >> 45);
}

static inline void VecNormalize(Vec *v) {
    if (v->x == 0 && v->y == 0 && v->z == 0) {
        VecCopy(v, &data_020ff9b4);
    } else {
        VecNormalizeFx(v, v);
    }
}

/* Slides a motion vector against up to three contact planes found by func_01ffa338. */
void func_0204dbd8(Result *out, Body *body, void *arg2, void *arg3, Vec *move, void *arg5) {
    Hit hit0;
    Vec move1;
    Hit hit1;
    Vec move2;
    Hit hit2;
    Vec axis;
    Vec move3;
    Hit hit3;
    Plane *p;
    s32 d;

    HitInit(&hit0);
    func_01ffa338(body, arg2, arg3, move, arg5, &hit0);

    out->pos.x = 0;
    out->pos.y = 0;
    out->pos.z = 0;
    out->f0c   = 0;
    out->f10   = 0;
    out->count = 0;
    p          = out->planes;
    do {
        p->id       = 0;
        p->normal.x = 0;
        p->normal.y = 0;
        p->normal.z = 0;
        p++;
    } while (p < out->planes + 3);
    out->f10 = hit0.f18;
    out->f0c = hit0.f14;

    if (hit0.dist > 0x1000) {
        VecCopy(&out->pos, move);
        out->count = 0;
        out->f10   = 0;
        return;
    }

    /* First slide, written out: move1 = move + n0 * (margin - dot(move, n0)). */
    if (VecIsZero(move)) {
        move1.x = data_020ff9b4.x;
        move1.y = data_020ff9b4.y;
        move1.z = data_020ff9b4.z;
    } else {
        int k;
        int x;
        int y;
        int z;
        k = VecDot(move, &hit0.normal);
        k = data_020fe498[1] - k;
        z = move->z;
        z += FxMul(hit0.normal.z, k);
        y       = FxMul(hit0.normal.y, k);
        x       = FxMul(hit0.normal.x, k);
        y       = move->y + y;
        x       = move->x + x;
        move1.x = x;
        move1.y = y;
        move1.z = z;
    }
    HitInit(&hit1);
    func_01ffa338(body, arg2, arg3, &move1, arg5, &hit1);
    if (hit1.dist > 0x1000) {
        VecCopy(&out->pos, &move1);
        out->count = 1;
        PlaneSet(&out->planes[0], &hit0);
        return;
    }

    if (hit1.normal.x == hit0.normal.x && hit1.normal.y == hit0.normal.y && hit1.normal.z == hit0.normal.z) {
        PlaneSet(&out->planes[0], &hit0);
        PlaneSet(&out->planes[1], &hit1);
        out->count = 2;
        VecCopy(&out->pos, &data_020ff9b4);
        VecCopy(&body->f60, &data_020ff9b4);
        return;
    }

    if (out->f0c == 0) {
        out->f0c = hit1.f14;
    }
    Project(&move2, &move1, &hit1.normal);

    if (VecDot(&move2, &hit0.normal) >= 0) {
        HitInit(&hit2);
        func_01ffa338(body, arg2, arg3, &move2, arg5, &hit2);
        if (hit2.dist <= 0x1000) {
            VecCopy(&out->pos, &data_020ff9b4);
            VecCopy(&body->f60, &data_020ff9b4);
            if (out->f0c == 0) {
                out->f0c = hit2.f14;
            }
            out->count = 3;
            PlaneSet(&out->planes[0], &hit0);
            PlaneSet(&out->planes[1], &hit1);
            PlaneSet(&out->planes[2], &hit2);
            return;
        }
        VecCopy(&out->pos, &move2);
        out->count = 1;
        PlaneSet(&out->planes[0], &hit1);
        return;
    }

    func_02039eec(&axis, &hit0.normal, &hit1.normal);
    VecNormalize(&axis);
    d       = VecDot(&axis, move);
    move3.x = FxMul(axis.x, d);
    move3.y = FxMul(axis.y, d);
    move3.z = FxMul(axis.z, d);
    HitInit(&hit3);
    func_01ffa338(body, arg2, arg3, &move3, arg5, &hit3);
    PlaneSet(&out->planes[0], &hit0);
    PlaneSet(&out->planes[1], &hit1);
    if (hit3.dist <= 0x1000) {
        VecCopy(&out->pos, &data_020ff9b4);
        VecCopy(&body->f60, &data_020ff9b4);
        if (out->f0c == 0) {
            out->f0c = hit3.f14;
        }
        out->count = 3;
        PlaneSet(&out->planes[2], &hit3);
        return;
    }
    VecCopy(&out->pos, &move3);
    out->count = 2;
}
