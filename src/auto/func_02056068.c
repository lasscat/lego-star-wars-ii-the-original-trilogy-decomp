#include "m2c.h"

M2C_UNK func_020b8f70(u8, u8);                      /* extern */

void func_02056068(s32 arg0, void *arg1) {
    func_020b8f70(M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
}
