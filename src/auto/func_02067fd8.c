#include "m2c.h"

M2C_UNK func_02001688(M2C_UNK);                     /* extern */
M2C_UNK func_020016c0();                            /* extern */
M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_0206802c();                            /* extern */
extern M2C_UNK data_021019f4;
extern s32 data_027e02a4;

void func_02067fd8(void *arg0) {
    func_0206802c();
    if (M2C_FIELD(arg0, s8 *, 0x38) == -1) {
        return;
    }
    func_02001688(1);
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_020016c0();
    M2C_FIELD(arg0, s8 *, 0x38) = -1;
}
