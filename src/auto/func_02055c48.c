#include "m2c.h"

M2C_UNK func_020559e4(s32);                         /* extern */
extern M2C_UNK data_02101dbc;
extern M2C_UNK data_02101dcc;

void func_02055c48(s32 arg0) {
    func_020559e4((arg0 * 0x18) + (s32) &data_02101dcc);
    ((s8 *) &data_02101dbc)[arg0] = 0;
}
