#include "m2c.h"

M2C_UNK func_0205ce5c(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0205e84c();                            /* extern */
M2C_UNK func_020861bc(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104d90;
extern s32 data_021092f4;
extern void **data_0210b348;
extern s32 data_027e02a8;

void func_020707a4(void) {
    M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 4)(data_0210b348);
    if (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0) {
        M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 8)(data_0210b348);
        do {

        } while (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0);
    }
    data_027e02a8 &= ~0x40;
    if (data_021092f4 != 0) {
        func_0205e84c();
    }
    data_021092f4 = 0;
    func_0205ce5c(&data_021027f8, 1);
    func_020861bc(&data_02104d90, 0xB, 0);
}
