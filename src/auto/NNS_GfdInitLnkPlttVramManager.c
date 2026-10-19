#include "m2c.h"

M2C_UNK NNS_GfdResetLnkPlttVramState();                            /* extern */
extern M2C_UNK *NNS_GfdDefaultFuncAllocPlttVram;
extern M2C_UNK *NNS_GfdDefaultFuncFreePlttVram;
extern M2C_UNK data_02112644;
extern M2C_UNK NNS_GfdAllocLnkPlttVram;
extern M2C_UNK NNS_GfdFreeLnkPlttVram;

void NNS_GfdInitLnkPlttVramManager(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_02112644, s32 *, 8)    = arg0;
    M2C_FIELD(&data_02112644, s32 *, 0xC)  = arg1;
    M2C_FIELD(&data_02112644, s32 *, 0x10) = arg2;
    NNS_GfdResetLnkPlttVramState();
    if (arg3 == 0) {
        return;
    }
    NNS_GfdDefaultFuncAllocPlttVram = &NNS_GfdAllocLnkPlttVram;
    NNS_GfdDefaultFuncFreePlttVram  = &NNS_GfdFreeLnkPlttVram;
}
