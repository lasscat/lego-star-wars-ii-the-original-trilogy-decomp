#include "m2c.h"

M2C_UNK func_02001990(void *, M2C_UNK);             /* extern */

void func_02020e84(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x212) != 0x13F) {
        M2C_FIELD(arg0, s8 *, 0x1BC) = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1BC) = 7;
    M2C_FIELD(arg0, s32 *, 8)    = (s32) (M2C_FIELD(arg0, s32 *, 8) | 1);
    func_02001990(arg0, 1);
}
