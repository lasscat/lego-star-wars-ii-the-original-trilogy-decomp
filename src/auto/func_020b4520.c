#include "m2c.h"

M2C_UNK func_020b4564();                            /* extern */
extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

void func_020b4520(s32 arg0, u32 arg1) {
    u32 var_r1;
    void *temp_r3;

    var_r1 = arg1;
    temp_r3 = *((M2C_UNK *)((s8 *)&data_0210dafc + (arg0 * 4)));
    if (temp_r3 == NULL) {
        return;
    }
    data_0210daf0 = temp_r3;
    if (var_r1 < 0x20U) {
        var_r1 = 0x20;
    } else if (var_r1 > 0xFFU) {
        var_r1 = 0xFF;
    }
    M2C_FIELD(temp_r3, s8 *, 0x2B) = (s8) var_r1;
    func_020b4564(arg0);
}
