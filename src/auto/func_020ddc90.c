#include "m2c.h"

M2C_UNK func_020cd288(void *, M2C_UNK *, void *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_020cd54c(void *);                      /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
M2C_UNK func_020ddd1c(M2C_UNK *);                   /* extern */
extern void *data_0211e628;
extern M2C_UNK data_0211e62c;
extern M2C_UNK data_0211ea50;
extern M2C_UNK func_020ddd30;

void func_020ddc90(void *arg0) {
    s32 temp_r4;

    temp_r4 = func_020ce804();
    if (data_0211e628 == NULL) {
        data_0211e628 = arg0;
        func_020ddd1c(arg0 + 0xC4);
        func_020ddd1c(&data_0211e62c);
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        func_020cd288(arg0, &func_020ddd30, arg0, &data_0211ea50, 0x400, 0x14);
        func_020cd54c(arg0);
    }
    func_020ce818(temp_r4);
}
