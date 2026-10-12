#include "m2c.h"

M2C_UNK func_020b4564(u8);                          /* extern */
M2C_UNK func_020b45ac(u8);                          /* extern */
extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

void func_020b4018(s32 arg0) {
    void *temp_r1;

    temp_r1 = *((M2C_UNK *)((s8 *)&data_0210dafc + (arg0 * 4)));
    if (temp_r1 == NULL) {
        return;
    }
    data_0210daf0 = temp_r1;
    if (M2C_FIELD(temp_r1, u8 *, 0x25) != 2) {
        return;
    }
    func_020b4564(M2C_FIELD(temp_r1, u8 *, 0x39));
    func_020b45ac(M2C_FIELD(data_0210daf0, u8 *, 0x39));
    M2C_FIELD(data_0210daf0, s32 *, 0x18) = 0;
    M2C_FIELD(data_0210daf0, s8 *, 0x25) = 1;
}
