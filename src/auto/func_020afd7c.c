#include "m2c.h"

s32 func_020af8bc(M2C_UNK);                         /* extern */
M2C_UNK func_020afcac(M2C_UNK);                     /* extern */
M2C_UNK func_020cea74();                            /* extern */
s32 func_020dc9e8(M2C_UNK);                         /* extern */

void func_020afd7c(M2C_UNK arg0, M2C_UNK arg1) {
    func_020afcac(2);
    if (func_020dc9e8(arg1) != 0) {
        func_020afcac(7);
        return;
    }
    if (func_020af8bc(arg0) != 0) {
        return;
    }
    func_020cea74();
}
