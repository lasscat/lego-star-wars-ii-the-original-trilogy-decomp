#include "m2c.h"

M2C_UNK func_020100a4(M2C_UNK **);                  /* extern */
extern M2C_UNK data_020fce50;

M2C_UNK **func_0200c164(M2C_UNK **arg0) {
    u32 var_r5;
    M2C_UNK **var_r6;
    void **temp_r0;

    var_r5 = 0;
    var_r6 = arg0;
    *arg0  = &data_020fce50;
    do {
        temp_r0 = M2C_FIELD(var_r6, void ***, 0x1D0);
        if (temp_r0 != NULL) {
            if (temp_r0 != NULL) {
                M2C_FIELD(*temp_r0, M2C_UNK(**)(), 4)(temp_r0);
            }
            M2C_FIELD(var_r6, void ***, 0x1D0) = NULL;
        }
        var_r5 += 1;
        var_r6 = (M2C_UNK **) ((u8 *) var_r6 + 0x28);
    } while (var_r5 < 0xCU);
    func_020100a4(arg0);
    return arg0;
}
