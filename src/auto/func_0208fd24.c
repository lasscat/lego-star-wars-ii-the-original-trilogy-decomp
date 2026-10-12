#include "m2c.h"

s32 func_02093f6c(u8);                              /* extern */
M2C_UNK func_020b3718(M2C_UNK *);                   /* extern */
M2C_UNK func_020b3abc(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_027e0bd0;

void func_0208fd24(void *arg0) {
    func_020b3abc(&data_027e0bd0, func_02093f6c(M2C_FIELD(arg0, u8 *, 0x479)));
    func_020b3718(&data_027e0bd0);
}
