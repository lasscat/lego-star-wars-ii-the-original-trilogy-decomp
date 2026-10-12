#include "m2c.h"

s32 func_0201c7b4(M2C_UNK, void *);                 /* extern */
s32 func_0201c828(M2C_UNK);                         /* extern */

s32 func_020abd64(void *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, s32 *, 0x10) == func_0201c828(arg1)) && (func_0201c7b4(arg1, arg0 + 0x14) != 0)) {
        return 1;
    }
    return 0;
}
