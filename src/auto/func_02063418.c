#include "m2c.h"

M2C_UNK func_02063054();                            /* extern */
M2C_UNK func_02063610(s32, M2C_UNK, s32);           /* extern */
extern M2C_UNK data_02104364;

void func_02063418(s32 arg0) {
    func_02063054();
    func_02063610((arg0 * 0xA) + 2, 0xA, M2C_FIELD(&data_02104364, s32 *, 0x20));
}
