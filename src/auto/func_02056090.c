#include "m2c.h"

M2C_UNK func_02068134(M2C_UNK *);                   /* extern */
M2C_UNK func_02068260(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_027e0864;

void func_02056090(s32 arg0, u8 *arg1) {
    func_02068260(&data_027e0864, *arg1);
    func_02068134(&data_027e0864);
}
