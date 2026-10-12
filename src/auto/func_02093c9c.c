#include "m2c.h"

M2C_UNK func_02001688(M2C_UNK);                     /* extern */
M2C_UNK func_020016c0();                            /* extern */
M2C_UNK func_0200fae8();                            /* extern */
M2C_UNK func_0200faf8();                            /* extern */
M2C_UNK func_02093c6c();                            /* extern */
M2C_UNK func_020b9088();                            /* extern */
M2C_UNK func_020b909c();                            /* extern */
M2C_UNK func_020b918c();                            /* extern */
M2C_UNK func_020b91c8();                            /* extern */
M2C_UNK func_020b9248();                            /* extern */
extern s32 data_027e02a8;

void func_02093c9c(void) {
    func_02093c6c();
    if (data_027e02a8 & 3) {
        func_02001688(0);
        func_0200fae8();
        func_020016c0();
        func_02001688(1);
        func_0200fae8();
        func_020016c0();
        func_020b9248();
        func_020b918c();
        func_020b9088();
        return;
    }
    func_02001688(1);
    func_0200faf8();
    func_020016c0();
    func_02001688(0);
    func_0200faf8();
    func_020016c0();
    func_020b91c8();
    func_020b909c();
}
