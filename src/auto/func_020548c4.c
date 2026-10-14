#include "m2c.h"

M2C_UNK func_01ff8000(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_0205e6e0(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_020548c4(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    switch (arg0) {                                 /* irregular */
        case 0:
            func_0205e6e0(arg2, arg1, arg3);
            return;
        case 3:
            func_01ff8000(arg1, arg2, 0);
            return;
    }
}
