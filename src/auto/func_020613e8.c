#include "m2c.h"

typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0x494];
    s32 speed;
    u16 rot[3];
    u8 pad49e[2];
    Vec3 dir;
    u8 randomize;
    u8 pad4ad[3];
    Vec3 color;
    u8 phase;
} Obj;

typedef struct {
    u8 pad0[0x1e];
    u16 f1e;
    u8 pad20[0xb];
    u8 f2b;
} Cfg;

extern Cfg *data_0210daf4[8];
extern Vec3 data_020ff9b4;
extern const s16 data_020f88c4[];

s32 func_02062ab4(s32 lo, s32 hi);
void func_02007f24(s32 *out, f64 d);
s32 FX_Div(s32 a, s32 b);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline Vec3 *vec_init(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x << 12;
    v->y = y << 12;
    v->z = z << 12;
    return v;
}

static inline void vec_normalize(const Vec3 *src, Vec3 *dst) {
    s64 t;
    s64 div;
    s32 sqrt;

    t = (s64) src->x * src->x;
    t += (s64) src->y * src->y;
    t += (s64) src->z * src->z;

    (*(vu16 *) 0x04000280) = 2;
    (*(vu64 *) 0x04000290) = 1LL << 56;
    (*(vu64 *) 0x04000298) = t;
    (*(vu16 *) 0x040002B0) = 1;
    (*(u64 *) 0x040002B8)  = t << 2;

    while ((*(vu16 *) 0x040002B0) & 0x8000) {
    }
    sqrt = (s32) (*(vu32 *) 0x040002B4);

    while ((*(vu16 *) 0x04000280) & 0x8000) {
    }
    div = (s64) (*(u64 *) 0x040002A0);
    div *= sqrt;

    dst->x = (s32) ((div * src->x + (1LL << 44)) >> 45);
    dst->y = (s32) ((div * src->y + (1LL << 44)) >> 45);
    dst->z = (s32) ((div * src->z + (1LL << 44)) >> 45);
}

void func_020613e8(Obj *obj) {
    s32 fx;
    Vec3 v;
    s32 t;

    if (obj->randomize) {
        vec_set(&obj->dir, vec_init(&v, func_02062ab4(-100, 100), func_02062ab4(-100, 100), func_02062ab4(-100, 100)));
        obj->randomize = 0;
    }

    if (data_0210daf4[2] != NULL) {
        if (data_0210daf4[2]->f1e == 0) {
            vec_set(&obj->color, &data_020ff9b4);
            obj->phase = 0;
        }
        obj->speed = FX_Div(0x3c000, FX_Div(0x1f000, FX_Div(data_0210daf4[2]->f2b << 12, 0x3c000)));
        if (obj->speed >= 0x1f000) {
            func_02007f24(&fx, 30.99);
            obj->speed = fx;
        }
    } else {
        obj->speed = 0x1000;
    }

    switch (obj->phase) {
        case 0:
        default:
            obj->color.x += obj->speed;
            if (obj->color.x >= 0x1f000) {
                obj->color.x = 0x1f000 - (s32) (obj->color.x - 0x1f000);
                obj->phase++;
            }
            break;
        case 1:
            obj->color.x -= obj->speed;
            if (obj->color.x <= 0) {
                obj->color.x = -obj->color.x;
                obj->phase++;
            }
            break;
        case 2:
            obj->color.y += obj->speed;
            if (obj->color.y >= 0x1f000) {
                obj->color.y = 0x1f000 - (s32) (obj->color.y - 0x1f000);
                obj->phase++;
            }
            break;
        case 3:
            obj->color.y -= obj->speed;
            if (obj->color.y <= 0) {
                obj->color.y = -obj->color.y;
                obj->phase++;
            }
            break;
        case 4:
            obj->color.z += obj->speed;
            if (obj->color.z >= 0x1f000) {
                obj->color.z = 0x1f000 - (s32) (obj->color.z - 0x1f000);
                obj->phase++;
            }
            break;
        case 5:
            obj->color.z -= obj->speed;
            if (obj->color.z <= 0) {
                obj->color.z = -obj->color.z;
                obj->phase++;
            }
            break;
        case 6:
            obj->color.z += obj->speed;
            obj->color.x += obj->speed;
            obj->color.y += obj->speed;
            if (obj->color.z >= 0x1f000) {
                obj->color.z = 0x1f000 - (s32) (obj->color.z - 0x1f000);
                obj->color.x = 0x1f000 - (s32) (obj->color.x - 0x1f000);
                obj->color.y = 0x1f000 - (s32) (obj->color.y - 0x1f000);
                obj->phase++;
            }
            break;
        case 7:
            obj->color.z -= obj->speed;
            obj->color.x -= obj->speed;
            obj->color.y -= obj->speed;
            if (obj->color.z <= 0) {
                obj->color.z = -obj->color.z;
                obj->color.x = -obj->color.x;
                obj->color.y = -obj->color.y;
                obj->phase   = 0;
            }
            break;
    }

    /* Rotate dir about X, Y, then Z by rot[0..2]. data_020f88c4 holds Q12
     * (sin, cos) pairs indexed by angle >> 4. t is the shared product temp of
     * the X and Y rotations. */
    {
        s32 s;
        s32 c;
        s32 y;
        s32 z;
        s32 ny;
        s32 nz;

        s          = data_020f88c4[(obj->rot[0] >> 4) * 2];
        c          = data_020f88c4[(obj->rot[0] >> 4) * 2 + 1];
        y          = obj->dir.y;
        z          = obj->dir.z;
        ny         = (s32) (((s64) z * s + 0x800) >> 12);
        ny         = (s32) (((s64) y * c + 0x800) >> 12) - ny;
        t          = (s32) (((s64) y * s + 0x800) >> 12);
        nz         = (s32) (((s64) z * c + 0x800) >> 12);
        obj->dir.y = ny;
        obj->dir.z = nz + t;
    }
    {
        s32 s;
        s32 c;
        s32 x;
        s32 z;
        s32 nx;

        s          = data_020f88c4[(obj->rot[1] >> 4) * 2];
        c          = data_020f88c4[(obj->rot[1] >> 4) * 2 + 1];
        x          = obj->dir.x;
        z          = obj->dir.z;
        t          = (s32) (((s64) z * s + 0x800) >> 12);
        nx         = (s32) (((s64) x * c + 0x800) >> 12);
        obj->dir.x = nx + t;
        t          = (s32) (((s64) x * s + 0x800) >> 12);
        t          = (s32) (((s64) z * c + 0x800) >> 12) - t;
        obj->dir.z = t;
    }
    {
        s32 s;
        s32 c;
        s32 x;
        s32 y;
        s32 nx;
        s32 ny;
        s64 q;

        s  = data_020f88c4[(obj->rot[2] >> 4) * 2];
        c  = data_020f88c4[(obj->rot[2] >> 4) * 2 + 1];
        x  = obj->dir.x;
        y  = obj->dir.y;
        nx = (s32) (((s64) y * s + 0x800) >> 12);
        nx = (s32) (((s64) x * c + 0x800) >> 12) - nx;
        q  = (s64) x * s;
        q  = (q + 0x800) >> 12;
        ny = (s32) (((s64) y * c + 0x800) >> 12);
        ny += (s32) q;
        obj->dir.x = nx;
        obj->dir.y = ny;
    }

    if (obj->dir.x == 0 && obj->dir.y == 0 && obj->dir.z == 0) {
        vec_set(&obj->dir, &data_020ff9b4);
    } else {
        vec_normalize(&obj->dir, &obj->dir);
    }
}
