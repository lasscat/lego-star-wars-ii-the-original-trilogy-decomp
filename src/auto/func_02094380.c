#include "m2c.h"

M2C_UNK func_0205d6f8(void *, M2C_UNK);             /* extern */
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_02064f48;
extern M2C_UNK func_02064f68;

void *func_02094380(void *arg0) {
    func_0205d6f8(arg0, 0x1E);
    func_0205d6f8(arg0 + 0x38, 0xA);
    func_0205d6f8(arg0 + 0x70, 0xA);
    func_020e46bc(arg0 + 0xB0, 4, 0x10, &func_02064f48, &func_02064f68);
    M2C_FIELD(arg0, s8 *, 0xF2) = 0x10;
    M2C_FIELD(arg0, s8 *, 0xF3) = 0x10;
    M2C_FIELD(arg0, s8 *, 0xF4) = 0x10;
    M2C_FIELD(arg0, s8 *, 0xF5) = 9;
    M2C_FIELD(arg0, s16 *, 0xF0) = 0;
    M2C_FIELD(arg0, s8 *, 0xF6) = 0;
    M2C_FIELD(arg0, s8 *, 0xF7) = 0;
    M2C_FIELD(arg0, s8 *, 0xF8) = 0;
    return arg0;
}
