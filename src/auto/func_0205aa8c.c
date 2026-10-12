#include "m2c.h"

M2C_UNK func_0205aad4();                            /* extern */
M2C_UNK func_0205aff0();                            /* extern */
M2C_UNK func_020d2870(M2C_UNK);                     /* extern */
s32 func_020d2f70(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_02102714;
extern M2C_UNK data_027e0340;

void func_0205aa8c(void) {
    func_020d2870(3);
    func_020d2f70(&data_02102714, func_020d2f70(NULL, 0));
    M2C_FIELD(&data_027e0340, s8 *, 0x49) = 0;
    M2C_FIELD(&data_027e0340, s8 *, 0x48) = 0;
    func_0205aad4();
    func_0205aff0();
}
