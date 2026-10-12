#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
s32 func_020d7d48(M2C_UNK *);                       /* extern */
extern M2C_UNK data_020fff80;
extern M2C_UNK data_020fff94;
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b720;

s32 func_020ad75c(void) {
    s32 temp_r0;

    func_020ad528(&data_020fff80);
    temp_r0 = func_020d7d48(&data_0210b720);
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = temp_r0;
    if (temp_r0 == 0) {
        return 1;
    }
    func_020ad528(&data_020fff94);
    return 0;
}
