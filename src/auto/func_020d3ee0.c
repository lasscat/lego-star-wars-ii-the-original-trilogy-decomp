#include "m2c.h"

M2C_UNK func_020ce868(s32);                         /* extern */
M2C_UNK func_020d3ccc(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_020d3eb8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020d3fb4(s32 *, s32 *);                /* extern */
s32 func_020d4340(M2C_UNK);                         /* extern */
s32 func_020d4360();                                /* extern */

void func_020d3ee0(M2C_UNK arg0, M2C_UNK arg1) {
    s32 sp4;
    s32 sp0;

    func_020ce868(0x996A00);
    if (func_020d4360() != 1) {
        func_020d3fb4(&sp4, &sp0);
        if (sp4 != 0) {
            func_020d3eb8(0, 0);
        }
        if (sp0 != 0) {
            func_020d3eb8(1, 0);
        }
        if (func_020d4340(1) == 0) {
            do {
                func_020ce868(0x996A00);
            } while (func_020d4340(1) == 0);
        }
    }
    func_020d3ccc(0xE, arg0, arg1);
}
