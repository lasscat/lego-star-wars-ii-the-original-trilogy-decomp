#include "m2c.h"

M2C_UNK func_020d2898(M2C_UNK *);                   /* extern */
s32 func_020d2b78(M2C_UNK *, M2C_UNK *);            /* extern */
extern M2C_UNK data_020fe554;
extern M2C_UNK data_027e0340;

void func_0205aad4(void) {
    func_020d2898(&data_027e0340);
    M2C_FIELD(&data_027e0340, s8 *, 0x49) = 1;
    if (func_020d2b78(&data_027e0340, &data_020fe554) != 0) {
        M2C_FIELD(&data_027e0340, s8 *, 0x48) = 1;
    }
    M2C_FIELD(&data_027e0340, s8 *, 0x49) = 0;
}
