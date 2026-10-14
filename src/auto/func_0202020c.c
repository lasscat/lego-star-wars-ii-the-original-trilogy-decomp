#include "m2c.h"

M2C_UNK func_02011384();                            /* extern */
M2C_UNK func_020202bc(void *);                      /* extern */
extern M2C_UNK data_020fd538;

void *func_0202020c(void *arg0, s32 arg1) {
    func_02011384();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd538;
    M2C_FIELD(arg0, s32 *, 0x224)  = 0;
    M2C_FIELD(arg0, s16 *, 0x1BE)  = 0x78;
    M2C_FIELD(arg0, s8 *, 0x1BC)   = 0;
    M2C_FIELD(arg0, s32 *, 0x218)  = 0;
    M2C_FIELD(arg0, s32 *, 0x21C)  = 0;
    if (arg1 == 0x185) {
        func_020202bc(arg0);
    } else if (arg1 != 0x57) {
        M2C_FIELD(arg0, s8 *, 0x1BC) = 2;
    } else {
        M2C_FIELD(arg0, s8 *, 0x1BC) = 6;
        func_020202bc(arg0);
    }
    return arg0;
}
