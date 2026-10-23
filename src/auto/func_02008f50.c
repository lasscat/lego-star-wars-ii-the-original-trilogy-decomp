#include "m2c.h"

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;

extern Vec data_020ff9b4;
extern s32 FX_Div(s32 num, s32 den);

void func_02008f50(Vec *out, volatile s32 a, Vec *b, Vec v) {
    s64 t;
    s32 sqrt;
    s64 div;
    s32 scale;

    if ((M2C_FIELD(&v, s32 *, 0) == 0) && (M2C_FIELD(&v, s32 *, 4) == 0) && (M2C_FIELD(&v, s32 *, 8) == 0)) {
        if (&v != &data_020ff9b4) {
            v.x = M2C_FIELD(&data_020ff9b4, s32 *, 0);
            v.y = M2C_FIELD(&data_020ff9b4, s32 *, 4);
            v.z = M2C_FIELD(&data_020ff9b4, s32 *, 8);
        }
    } else {
        t = (s64) v.x * v.x;
        t += (s64) v.y * v.y;
        t += (s64) v.z * v.z;

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

        v.x = (s32) ((div * v.x + (1LL << 44)) >> 45);
        v.y = (s32) ((div * v.y + (1LL << 44)) >> 45);
        v.z = (s32) ((div * v.z + (1LL << 44)) >> 45);
    }

    scale = FX_Div(a - b->y, v.y);

    out->x = 0;
    out->y = 0;
    out->z = 0;
    out->x = b->x + (s32) (((s64) scale * v.x + 0x800) >> 12);
    out->y = a;
    out->z = b->z + (s32) (((s64) scale * v.z + 0x800) >> 12);
}
