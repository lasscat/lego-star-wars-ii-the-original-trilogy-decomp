#include "m2c.h"

M2C_UNK func_020b3d08(M2C_UNK, u16, u8, u8);        /* extern */
M2C_UNK func_020b94e4();                            /* extern */
M2C_UNK func_020b94fc();                            /* extern */
extern u8 data_02100a00[];
extern u8 data_02100a02[];
extern u8 data_02100a03[];
extern volatile u8 data_0210db14[];

void func_020b90e4(u32 arg0, u8 arg1) {
    u32 var_r5;
    u8 var_r4;
    u8 temp_r0;
    u8 temp_r2;
    u16 temp_r1;

    var_r5 = arg0;
    var_r4 = arg1;
    if (data_0210db14[0xA] & 0x20) {
        return;
    }
    if (var_r5 >= 0x1DU) {
        var_r5 = 0;
    }
    if ((var_r5 == data_0210db14[9]) && !(data_0210db14[0xA] & 2)) {
        return;
    }
    func_020b94e4();
    temp_r1 = *(u16 *) (data_02100a00 + var_r5 * 4);
    temp_r2 = data_02100a02[var_r5 * 4];
    temp_r0 = data_02100a03[var_r5 * 4];
    if (var_r4 == 0xFF) {
        var_r4 = temp_r0;
    }
    func_020b3d08(0, temp_r1, temp_r2, var_r4);
    data_0210db14[0xA] = data_0210db14[0xA] & ~2;
    if (!(data_0210db14[0xA] & 1)) {
        data_0210db14[9] = var_r5;
    }
    func_020b94fc();
}
