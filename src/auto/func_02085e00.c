#include "m2c.h"
M2C_UNK func_020632b4(void *, M2C_UNK);
extern void *data_0210930c[];
void func_02085e00(void *arg0, s16 *arg1) {
    u32 var_r4;
    void *temp_r2;
    var_r4                    = 0;
    M2C_FIELD(arg1, s32 *, 0) = 0x88CC44FF;
    do {
        temp_r2 = data_0210930c[0x13 + var_r4];
        if (temp_r2 != NULL) {
            arg1[2 + var_r4] = (s16) M2C_FIELD(temp_r2, u8 *, 0x6BB);
        } else {
            arg1[2 + var_r4] = 0x64;
        }
        var_r4 += 1;
    } while (var_r4 < 2U);
    M2C_FIELD(arg1, u8 *, 8) = (u8) M2C_FIELD(arg0, u8 *, 0x455D);
    M2C_FIELD(arg1, u8 *, 9) = (u8) M2C_FIELD(arg0, u8 *, 0x455E);
    func_020632b4(arg1, 0xC);
}
