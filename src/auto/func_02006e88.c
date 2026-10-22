#include "m2c.h"

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 sc;
    Vec3 v;
} Out;

extern Vec3 data_020ff9b4;

void func_02007f24(s32 *arg0, s32 arg1, f32 arg2);

void func_02006e88(void *arg0, void *arg1) {
    Vec3 v;
    Out out;
    s32 q[4];
    s64 t;
    s32 sqrt;
    s64 div;
    s32 r;
    s32 dz;
    s32 dx;
    s32 a8;
    s32 b8;
    s32 a0;
    s32 b0;

    if (arg1 == 0) {
        return;
    }

    a8  = M2C_FIELD(arg1, s32 *, 0xb8);
    b8  = M2C_FIELD(arg0, s32 *, 0xb8);
    a0  = M2C_FIELD(arg1, s32 *, 0xb0);
    b0  = M2C_FIELD(arg0, s32 *, 0xb0);
    dz  = a8 - b8;
    dx  = a0 - b0;
    v.x = dx;
    v.z = dz;
    v.y = 0;

    r = M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), s32 *, 0x30);
    if (a8 >= b8 + r || a8 <= b8 - r) {
        v.x = 0;
    } else {
        v.z = 0;
    }

    if (v.x == 0 && v.y == 0 && v.z == 0) {
        if (&v != &data_020ff9b4) {
            v.x = data_020ff9b4.x;
            v.y = data_020ff9b4.y;
            v.z = data_020ff9b4.z;
        }
    } else {
        t = (s64) M2C_FIELD(&v, s32 *, 0) * M2C_FIELD(&v, s32 *, 0);
        t += (s64) M2C_FIELD(&v, s32 *, 4) * M2C_FIELD(&v, s32 *, 4);
        t += (s64) M2C_FIELD(&v, s32 *, 8) * M2C_FIELD(&v, s32 *, 8);

        (*(vu16 *) 0x04000280) = 2;
        (*(vu64 *) 0x04000290) = 1LL << 56;
        (*(vu64 *) 0x04000298) = t;

        (*(vu16 *) 0x040002b0) = 1;
        (*(u64 *) 0x040002b8)  = t << 2;

        while ((*(vu16 *) 0x040002b0) & 0x8000) {
        }
        sqrt = (s32) (*(vu32 *) 0x040002b4);

        while ((*(vu16 *) 0x04000280) & 0x8000) {
        }
        div = (s64) (*(u64 *) 0x040002a0);

        div *= sqrt;

        v.x = (s32) ((div * v.x + (1LL << 44)) >> 45);
        v.y = (s32) ((div * v.y + (1LL << 44)) >> 45);
        v.z = (s32) ((div * v.z + (1LL << 44)) >> 45);
    }

    out.v.x = v.x;
    out.v.y = v.y;
    out.v.z = v.z;

    func_02007f24(&out.sc, 0, 1.875f);

    M2C_FIELD(q, s32 *, 0)  = out.sc;
    M2C_FIELD(q, s32 *, 4)  = out.sc;
    out.v.x                 = (s32) (((s64) out.v.x * out.sc + 0x800) >> 12);
    M2C_FIELD(q, s32 *, 8)  = out.sc;
    out.v.y                 = (s32) (((s64) out.v.y * out.sc + 0x800) >> 12);
    M2C_FIELD(q, s32 *, 12) = out.sc;
    out.v.z                 = (s32) (((s64) out.v.z * out.sc + 0x800) >> 12);

    if (&M2C_FIELD(arg1, Vec3 *, 0x60) != &out.v) {
        M2C_FIELD(arg1, Vec3 *, 0x60).x = out.v.x;
        M2C_FIELD(arg1, Vec3 *, 0x60).y = out.v.y;
        M2C_FIELD(arg1, Vec3 *, 0x60).z = out.v.z;
    }
    M2C_FIELD(arg1, u32 *, 8) &= ~0x200;
    if (&M2C_FIELD(arg0, Vec3 *, 0x60) != &out.v) {
        M2C_FIELD(arg0, Vec3 *, 0x60).x = out.v.x;
        M2C_FIELD(arg0, Vec3 *, 0x60).y = out.v.y;
        M2C_FIELD(arg0, Vec3 *, 0x60).z = out.v.z;
    }
    M2C_FIELD(arg0, u32 *, 8) &= ~0x200;
}
