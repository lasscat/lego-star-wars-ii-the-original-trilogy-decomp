#include "m2c.h"

M2C_UNK func_0202bd80(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202c440(void *, u8);                  /* extern */
M2C_UNK func_0202c498(void *, u8);                  /* extern */
M2C_UNK func_0202c500(void *, u8);                  /* extern */
s32 func_020867ec(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_020ee898;
extern M2C_UNK data_020ee899;
extern M2C_UNK data_020ee89a;
extern M2C_UNK data_02104d90;

void func_0202c01c(void *arg0, void *arg1) {
    u8 temp_r4;

    M2C_FIELD(arg0, void **, 0x20) = arg1;
    temp_r4                        = M2C_FIELD(arg1, u8 *, 0x6BB);
    if (func_020867ec(&data_02104d90, 2) != 0) {
        func_0202c498(arg0, 9U);
    } else {
        func_0202c498(arg0, *((u8 *) ((s8 *) &data_020ee898 + (temp_r4 * 4))));
    }
    func_0202c440(arg0, *((u8 *) ((s8 *) &data_020ee89a + (temp_r4 * 4))));
    func_0202c500(arg0, *((u8 *) ((s8 *) &data_020ee899 + (temp_r4 * 4))));
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 0xC) != 2) {
        return;
    }
    func_0202bd80(arg0 + 0x28, 1);
}
