#include "m2c.h"

M2C_UNK func_020c84dc(M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_020c8510(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_020c889c(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_027e0cd0;
extern M2C_UNK data_027e0d44;
extern M2C_UNK data_027e0d74;

void func_020c4630(void) {
    func_020c889c(&data_027e0cd0, &data_027e0c60, &data_027e0d44);
    func_020c84dc(&data_027e0d44, &data_027e0d44, M2C_FIELD(&data_027e0c14, s32 *, 0xEC), M2C_FIELD(&data_027e0c14, s32 *, 0xF0), M2C_FIELD(&data_027e0c14, s32 *, 0xF4));
    func_020c8510(&data_027e0d44, &data_027e0d74);
}
