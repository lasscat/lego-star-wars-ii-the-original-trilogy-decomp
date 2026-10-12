#include "m2c.h"

M2C_UNK func_020d1134();                            /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_020d128c(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020dd660();                            /* extern */
M2C_UNK func_020dd930(M2C_UNK);                     /* extern */
M2C_UNK func_020dda2c();                            /* extern */
M2C_UNK func_020ddc90(M2C_UNK *);                   /* extern */
extern M2C_UNK data_0211e460;
extern M2C_UNK data_0211e540;
extern M2C_UNK func_020ddbe0;
extern M2C_UNK func_020ddc0c;
extern M2C_UNK func_020ddc7c;

void func_020dd978(void) {
    if (M2C_FIELD(&data_0211e460, s32 *, 8) != 0) {
        return;
    }
    M2C_FIELD(&data_0211e460, s32 *, 8) = 1;
    func_020dd660();
    M2C_FIELD(&data_0211e460, s32 *, 0xC) = 0;
    func_020d1134();
    do {

    } while (func_020d128c(0xD, 1) == 0);
    func_020d1240(0xD, &func_020ddbe0);
    func_020dda2c();
    func_020d1240(0xD, NULL);
    func_020d1240(0xD, &func_020ddc0c);
    M2C_FIELD(&data_0211e460, s32 *, 0x18) = 0;
    func_020ddc90(&data_0211e540);
    func_020d1240(0x11, &func_020ddc7c);
    func_020dd930(0);
}
