#include "m2c.h"

M2C_UNK func_0202969c();                            /* extern */

void func_02029664(void *arg0, void *arg1) {
    if ((arg0 + 0x70) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) M2C_FIELD(arg1, s32 *, 8);
    }
    M2C_FIELD(arg0, s8 *, 0x8F) = 1;
    func_0202969c();
}
