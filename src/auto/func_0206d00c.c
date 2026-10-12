#include "m2c.h"

M2C_UNK func_02001688(s32);                         /* extern */
M2C_UNK func_020016c0();                            /* extern */
M2C_UNK func_0200fae8();                            /* extern */
M2C_UNK func_0200faf8();                            /* extern */
M2C_UNK func_02093c6c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_0210930c;
extern s32 data_027e02a4;

void func_0206d00c(s32 arg0, s32 arg1) {
    func_02093c6c(&data_0210930c);
    if (arg1 != 0) {
        func_0200fae8();
        func_02001688(data_027e02a4 ^ 1);
        func_0200fae8();
        func_020016c0();
        return;
    }
    func_0200faf8();
    func_02001688(data_027e02a4 ^ 1);
    func_0200faf8();
    func_020016c0();
}
