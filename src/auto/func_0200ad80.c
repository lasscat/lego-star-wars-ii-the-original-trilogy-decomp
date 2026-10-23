#include "m2c.h"

extern M2C_UNK data_020ff9b4;

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

void func_0200ad80(s32 *arg0, s32 *arg1) {
    s64 t;
    s32 sqrt;
    s64 div;

    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];

    if ((arg0[0] == 0) && (arg0[1] == 0) && (arg0[2] == 0)) {
        if (arg0 == (s32 *) &data_020ff9b4) {
            return;
        }
        arg0[0] = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        arg0[1] = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        arg0[2] = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
        return;
    }

    t = (s64) M2C_FIELD(arg0, s32 *, 0) * M2C_FIELD(arg0, s32 *, 0);
    t += (s64) M2C_FIELD(arg0, s32 *, 4) * M2C_FIELD(arg0, s32 *, 4);
    t += (s64) M2C_FIELD(arg0, s32 *, 8) * M2C_FIELD(arg0, s32 *, 8);

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

    arg0[0] = (s32) ((div * arg0[0] + (1LL << 44)) >> 45);
    arg0[1] = (s32) ((div * arg0[1] + (1LL << 44)) >> 45);
    arg0[2] = (s32) ((div * arg0[2] + (1LL << 44)) >> 45);
}
