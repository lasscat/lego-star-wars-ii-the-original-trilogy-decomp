#include "m2c.h"

M2C_UNK func_020922f4(M2C_UNK *, s8, s8);
M2C_UNK func_02091b68(M2C_UNK *, s8);
extern M2C_UNK data_0210930c;

void func_020565d4(s32 arg0, u8 *arg1) {
    s8 var_ip;
    s8 var_r1;
    void *temp;

    var_r1 = -1;
    var_ip = 0;
loop_1:
    temp = ((s32 *) &data_0210930c)[var_ip + 0x13];
    if (temp == NULL) {
        goto end_1;
    }
    if (*arg1 == M2C_FIELD(temp, u8 *, 0x6BB)) {
        var_r1 = var_ip;
    }
    var_ip += 1;
    if ((s32) var_ip < 4) {
        goto loop_1;
    }
end_1:
    var_ip -= 1;
    if (var_r1 == -1) {
        return;
    }
    if (var_ip != var_r1) {
        func_020922f4(&data_0210930c, var_r1, var_ip);
    }
    func_02091b68(&data_0210930c, var_ip);
}
