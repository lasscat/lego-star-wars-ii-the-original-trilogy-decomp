#include "m2c.h"

M2C_UNK WM_GetSharedDataAddress(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_0210b520;
extern M2C_UNK data_0210b720;

void func_020ad884(s32 arg0, M2C_UNK arg1) {
    WM_GetSharedDataAddress(&data_0210b720, &data_0210b520, arg1);
}
