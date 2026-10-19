#include "m2c.h"

M2C_UNK NNS_GfdRegisterNewVramTransferTask(M2C_UNK, u32, s32, s32);      /* extern */
M2C_UNK GX_BeginLoadTex();                            /* extern */
M2C_UNK GX_LoadTex(s32, u32, s32);               /* extern */
M2C_UNK GX_EndLoadTex();                            /* extern */
M2C_UNK GX_BeginLoadTexPltt();                            /* extern */
M2C_UNK GX_LoadTexPltt(s32, u32, s32);               /* extern */
M2C_UNK GX_EndLoadTexPltt();                            /* extern */
M2C_UNK DC_FlushRange(s32, s32);                    /* extern */
extern s32 data_027e02a8;

void func_020651d0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 temp_r1;
    u32 temp_r2;
    u32 temp_r6;
    u32 temp_r9;
    u32 temp_r4;
    u32 temp_r8;

    if (arg3 != 0) {
        data_027e02a8 |= 0x80;
    }
    if (arg1 != 0) {
        temp_r2 = M2C_FIELD(arg0, s32 *, 0);
        temp_r8 = (u32) (temp_r2 << 0x10) >> 0xD;
        temp_r9 = ((u32) (temp_r2 & 0x7FFF0000) >> 0x10) * 0x10;
        if (arg3 != 0) {
            DC_FlushRange(arg1, temp_r9);
            GX_BeginLoadTex();
            GX_LoadTex(arg1, temp_r8, temp_r9);
            GX_EndLoadTex();
        } else {
            NNS_GfdRegisterNewVramTransferTask(0, temp_r8, arg1, temp_r9);
        }
    }
    if (arg2 != 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 8);
        temp_r4 = (u32) (temp_r1 << 0x10) >> 0xD;
        temp_r6 = ((u32) (temp_r1 & ~0xFFFF) >> 0x10) * 8;
        if (arg3 != 0) {
            DC_FlushRange(arg2, temp_r6);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(arg2, temp_r4, temp_r6);
            GX_EndLoadTexPltt();
        } else {
            NNS_GfdRegisterNewVramTransferTask(1, temp_r4, arg2, temp_r6);
        }
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 2);
    data_027e02a8 &= ~0x80;
}
