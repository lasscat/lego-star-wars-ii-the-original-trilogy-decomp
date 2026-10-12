#include "m2c.h"

M2C_UNK func_020b8724();                            /* extern */
extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

void func_020b3fd0(s32 arg0) {
    void *temp_r1;

    temp_r1 = *((M2C_UNK *)((s8 *)&data_0210dafc + (arg0 * 4)));
    if (temp_r1 == NULL) {
        return;
    }
    data_0210daf0 = temp_r1;
    if (M2C_FIELD(temp_r1, u8 *, 0x25) != 1) {
        return;
    }
    func_020b8724();
    M2C_FIELD(data_0210daf0, s8 *, 0x25) = 2;
}
