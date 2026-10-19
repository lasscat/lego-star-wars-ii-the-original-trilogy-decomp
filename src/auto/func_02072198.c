#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b01a8();                            /* extern */
s32 func_020b01bc();                                /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK *data_0210b348;

void func_02072198(s32 arg0) {
    func_020b01a8(arg0);
    while ((func_020b01bc() != 0) && (func_020b01bc() != 5) && (func_020b01bc() != 1)) {
    }
    M2C_FIELD(M2C_FIELD(data_0210b348, void **, 0), M2C_UNK(**)(), 4)(data_0210b348);
    if (M2C_FIELD(M2C_FIELD(data_0210b348, void **, 0), s32(**)(), 0x50)(data_0210b348) == 0) {
        do {
            M2C_FIELD(M2C_FIELD(data_0210b348, void **, 0), M2C_UNK(**)(), 8)(data_0210b348);
        } while (M2C_FIELD(M2C_FIELD(data_0210b348, void **, 0), s32(**)(), 0x50)(data_0210b348) == 0);
    }
    func_0205ecc4(&data_02102900, 0x20, 1, 0, 1, 0);
}
