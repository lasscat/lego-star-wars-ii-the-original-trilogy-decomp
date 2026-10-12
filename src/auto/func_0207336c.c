#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02062a40(u16);                         /* extern */
M2C_UNK func_02072e54();                            /* extern */
M2C_UNK func_02087044(M2C_UNK *);                   /* extern */
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02104d90;
extern s32 data_027e02a4;

void func_0207336c(void *arg0) {
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_02072e54();
    func_02062a40(M2C_FIELD(arg0, u16 *, 0xE0B2));
    func_02087044(&data_02104d90);
}
