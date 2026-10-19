#include "m2c.h"
s32 func_020d3a08();
M2C_UNK func_020d4010(s32);
M2C_UNK func_020d426c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK data_0211748c;
s32 func_020d3c38(s32 arg0, u32 arg1) {
    if (func_020d3a08() == 0) {
        return 1;
    }
    M2C_FIELD(&data_0211748c, s32 *, 4) = 0;
    func_020d4010(0x03006000);
    while (M2C_FIELD(&data_0211748c, volatile s32 *, 4) == 0) {
    }
    M2C_FIELD(&data_0211748c, s32 *, 4) = 0;
    M2C_FIELD(&data_0211748c, s32 *, 8) = 0;
    func_020d426c(0, 2, 0, 0);
    func_020d4010((arg0 & 0xFF) | 0x02006100);
    func_020d4010(((arg1 << 16) >> 16) | 0x01010000);
    return 0;
}
