#pragma opt_propagation off
#include "m2c.h"
M2C_UNK OS_DisableIrqMask(s32);
extern M2C_UNK OSi_IrqCallbackInfoIndex;
extern M2C_UNK OSi_IrqCallbackInfo;
extern M2C_UNK data_021153c4;
extern M2C_UNK data_021153c8;
extern M2C_UNK SDK_AUTOLOAD_DTCM_START;
void OSi_IrqCallback(s32 arg0) {
    s32 mask, temp_r5, enable, val;
    M2C_UNK (*temp_r1)(s32);
    temp_r5                                             = arg0 * 0xC;
    mask                                                = 1 << M2C_FIELD(&OSi_IrqCallbackInfoIndex, u16 *, arg0 * 2);
    temp_r1                                             = M2C_FIELD(&OSi_IrqCallbackInfo, M2C_UNK *, temp_r5);
    M2C_FIELD(&OSi_IrqCallbackInfo, M2C_UNK *, temp_r5) = 0;
    if (temp_r1 != NULL) {
        temp_r1(M2C_FIELD(&data_021153c8, M2C_UNK *, temp_r5));
    }
    val                                                = M2C_FIELD(&SDK_AUTOLOAD_DTCM_START, s32 *, 0x3FF8) | mask;
    enable                                             = M2C_FIELD(&data_021153c4, M2C_UNK *, temp_r5);
    M2C_FIELD(&SDK_AUTOLOAD_DTCM_START, s32 *, 0x3FF8) = val;
    if (enable != 0) {
        return;
    }
    OS_DisableIrqMask(mask);
}
