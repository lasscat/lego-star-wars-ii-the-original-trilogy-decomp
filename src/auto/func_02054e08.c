#include "m2c.h"

M2C_UNK func_02065600(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020cf660();                            /* extern */
M2C_UNK func_020cf67c();                            /* extern */
s32 func_020d5b94();                                /* extern */
M2C_UNK func_020d60c4(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02101d78;
extern M2C_UNK data_02101d8c;
extern s32 data_027e02a8;
extern M2C_UNK func_0205509c;

void func_02054e08(void) {
    func_020d60c4(&func_0205509c);
    data_027e02a8 |= 0x800;
    func_020cf660();
    M2C_FIELD(&data_02101d78, s32 *, 4) = func_020d5b94();
    func_020cf67c();
    func_02065600(&data_02101d8c, 2);
}
