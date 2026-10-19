#include "m2c.h"

M2C_UNK G3X_SetFog(M2C_UNK, M2C_UNK, u16, u16);  /* extern */
extern M2C_UNK data_027e0874;

void func_02059adc(void) {
    M2C_FIELD(&data_027e0874, s8 *, 0x40) = 0;
    G3X_SetFog(0, 0, M2C_FIELD(&data_027e0874, u16 *, 0x44), M2C_FIELD(&data_027e0874, u16 *, 0x46));
}
