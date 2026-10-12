#include "m2c.h"

M2C_UNK func_020cdad4(M2C_UNK *);                   /* extern */
M2C_UNK func_020d0878();                            /* extern */
M2C_UNK func_020d0fa0();                            /* extern */
extern s32 data_021157e4;
extern M2C_UNK data_021157e8;

void func_020d0840(void) {
    if (data_021157e4 != 0) {
        return;
    }
    data_021157e4 = 1;
    func_020cdad4(&data_021157e8);
    func_020d0878();
    func_020d0fa0();
}
