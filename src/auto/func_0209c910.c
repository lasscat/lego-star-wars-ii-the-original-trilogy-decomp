#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02072e54();                            /* extern */
M2C_UNK func_0209b6e4(s32);                         /* extern */
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02106d90;
extern s32 data_027e02a4;

void func_0209c910(void) {
    func_0209b6e4(M2C_FIELD(&data_02106d90, s32 *, 0xAD0));
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_02072e54();
}
