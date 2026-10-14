#include "m2c.h"

M2C_UNK func_02074d1c(void *);                      /* extern */
M2C_UNK func_02075640(void *);                      /* extern */

void func_02074cd0(void *arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    if ((arg0 + 4) != arg2) {
        M2C_FIELD(arg0, s32 *, 4)   = (s32) M2C_FIELD(arg2, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8)   = (s32) M2C_FIELD(arg2, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg2, s32 *, 8);
    }
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    func_02075640(arg0 + 0x10);
    func_02074d1c(arg0);
}
