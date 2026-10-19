#include "m2c.h"

s32 func_020af8bc(M2C_UNK);                         /* extern */
M2C_UNK func_020afcac(M2C_UNK);                     /* extern */
M2C_UNK OS_Terminate();                            /* extern */
s32 MB_StartParentFromIdle(M2C_UNK);                         /* extern */

void func_020afd7c(M2C_UNK arg0, M2C_UNK arg1) {
    func_020afcac(2);
    if (MB_StartParentFromIdle(arg1) != 0) {
        func_020afcac(7);
        return;
    }
    if (func_020af8bc(arg0) != 0) {
        return;
    }
    OS_Terminate();
}
