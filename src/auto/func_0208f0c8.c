#include "m2c.h"

M2C_UNK func_020632b4(s32 *, M2C_UNK);              /* extern */
s32 func_02085594();                                /* extern */
s32 func_0208559c(M2C_UNK);                         /* extern */

void func_0208f0c8(M2C_UNK arg0) {
    s32 sp0;

    sp0 = func_02085594();
    func_020632b4(&sp0, 4);
    sp0 = func_0208559c(arg0);
    func_020632b4(&sp0, 4);
}
