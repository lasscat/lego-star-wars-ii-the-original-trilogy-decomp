#include "m2c.h"

s32 func_020cac54();                                /* extern */
M2C_UNK MI_DmaCopy32(s32, M2C_UNK, s32, u32);      /* extern */
M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);           /* extern */
extern s32 GXi_DmaId;

void func_020cbdbc(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 temp_ip;

    temp_ip = func_020cac54();
    if ((GXi_DmaId != -1) && (arg2 > 0x30U)) {
        MI_DmaCopy32(GXi_DmaId, arg0, temp_ip + arg1, arg2);
        return;
    }
    MIi_CpuCopy32(arg0, temp_ip + arg1, arg2);
}
