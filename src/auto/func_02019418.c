#include "m2c.h"

M2C_UNK func_02018f68(void *, u8);                  /* extern */

void func_02019418(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x1C1) != 0) {
        return;
    }
    if ((M2C_FIELD(arg0, s32 *, 8) & 2) == 2) {
        return;
    }
    if (M2C_FIELD(arg1, s32 *, 0) != 0) {
        return;
    }
    func_02018f68(arg0, M2C_FIELD(arg1, u8 *, 4));
}
