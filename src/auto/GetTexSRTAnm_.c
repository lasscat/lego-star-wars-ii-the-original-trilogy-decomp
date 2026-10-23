#include "m2c.h"

s32 GetTexSRTAnmVectorVal_(s32 *, u32, s32, u32);
s32 GetTexSRTAnmSinCosVal_(s32 *, u32, s32, u32);

void GetTexSRTAnm_(s32 *arg0, s32 arg1, u32 arg2, void *arg3) {
    u16 off;
    u16 stride;
    u8 *row;
    u32 flags;
    s32 v1;
    s32 v2;
    u32 v3;
    s32 v4;
    s32 v5;

    u8 *tbl = (u8 *) arg0 + 8;

    off    = M2C_FIELD(arg0, u16 *, 0xE);
    stride = M2C_FIELD(tbl, u16 *, off);
    row    = tbl + off + 4;
    row += stride * arg1;

    flags = M2C_FIELD(arg3, u32 *, 0x0);

    v1 = GetTexSRTAnmVectorVal_(arg0, M2C_FIELD(row, u32 *, 0x18), M2C_FIELD(row, s32 *, 0x1C), arg2);
    v2 = GetTexSRTAnmVectorVal_(arg0, M2C_FIELD(row, u32 *, 0x20), M2C_FIELD(row, s32 *, 0x24), arg2);
    if (v1 == 0 && v2 == 0) {
        flags |= 4;
    } else {
        M2C_FIELD(arg3, s32 *, 0x24) = v1;
        M2C_FIELD(arg3, s32 *, 0x28) = v2;
        flags &= ~4;
    }

    v3 = GetTexSRTAnmSinCosVal_(arg0, M2C_FIELD(row, u32 *, 0x10), M2C_FIELD(row, s32 *, 0x14), arg2);
    if (v3 == 0x10000000) {
        flags |= 2;
    } else {
        M2C_FIELD(arg3, u16 *, 0x20) = (u16) v3;
        M2C_FIELD(arg3, u16 *, 0x22) = (u16) (v3 >> 16);
        flags &= ~2;
    }

    v4 = GetTexSRTAnmVectorVal_(arg0, M2C_FIELD(row, u32 *, 0x0), M2C_FIELD(row, s32 *, 0x4), arg2);
    v5 = GetTexSRTAnmVectorVal_(arg0, M2C_FIELD(row, u32 *, 0x8), M2C_FIELD(row, s32 *, 0xC), arg2);
    if (v4 == 0x1000 && v5 == 0x1000) {
        flags |= 1;
    } else {
        M2C_FIELD(arg3, s32 *, 0x18) = v4;
        M2C_FIELD(arg3, s32 *, 0x1C) = v5;
        flags &= ~1;
    }

    M2C_FIELD(arg3, u32 *, 0x0) = flags;
}
