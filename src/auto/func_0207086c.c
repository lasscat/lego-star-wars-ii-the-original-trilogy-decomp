#include "m2c.h"

M2C_UNK func_0205ce5c(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0205e84c();                            /* extern */
M2C_UNK func_020861bc(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104d90;
extern s32 data_021092f4;
extern void **data_0210b348;
extern s32 data_027e02a4;
extern s32 data_027e02a8;

void func_0207086c(void) {
    M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 8)(data_0210b348);
    if (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0) {
        do {
            M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 8)(data_0210b348);
        } while (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0);
    }
    data_027e02a8 &= ~((1 << data_027e02a4) | 0x40);
    func_020861bc(&data_02104d90, 0xB, 0);
    if (data_021092f4 != 0) {
        func_0205e84c();
    }
    data_021092f4 = 0;
    func_0205ce5c(&data_021027f8, 1);
}
