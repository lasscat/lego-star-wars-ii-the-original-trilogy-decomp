#include "m2c.h"

M2C_UNK func_0205ce5c(M2C_UNK *, u8);               /* extern */
M2C_UNK func_02073054(u8);                          /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104d2c;

void func_0206fbb4(void *arg0) {
    if ((u32) M2C_FIELD(&data_02104d2c, u8 *, 6) <= 1U) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x8C) = 5;
    func_02073054(M2C_FIELD(&data_02104d2c, u8 *, 6));
    func_0205ce5c(&data_021027f8, M2C_FIELD(&data_02104d2c, u8 *, 6));
}
