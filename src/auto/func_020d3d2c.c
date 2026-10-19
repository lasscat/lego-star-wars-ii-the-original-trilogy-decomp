#include "m2c.h"

s32 func_020d3a08();
M2C_UNK PMi_SendPxiData(s32);
extern M2C_UNK data_0211748c;
typedef struct {
    u16 a;
    u16 pad;
    s32 c;
} X;
extern X data_021174cc[8];

s32 func_020d3d2c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_020d3a08() == 0) {
        return 1;
    }
    M2C_FIELD(&data_0211748c, s32 *, 0x1C) = arg2;
    M2C_FIELD(&data_0211748c, s32 *, 0x20) = arg3;
    data_021174cc[arg0].a                  = 0;
    data_021174cc[arg0].c                  = arg1;
    PMi_SendPxiData((u8) arg0 | 0x03006500);
    return 0;
}
