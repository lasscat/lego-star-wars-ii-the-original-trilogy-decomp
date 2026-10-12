#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02055c48(M2C_UNK);                     /* extern */
M2C_UNK func_0205eb98();                            /* extern */
M2C_UNK func_02072e54();                            /* extern */
M2C_UNK func_0208f014(M2C_UNK);                     /* extern */
M2C_UNK func_020b909c();                            /* extern */
M2C_UNK func_020b91c8();                            /* extern */
extern M2C_UNK data_021019f4;
extern s32 data_027e02a4;

void func_0208e7e0(M2C_UNK arg0) {
    func_0205eb98();
    func_02072e54();
    func_0208f014(arg0);
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_020b91c8();
    func_020b909c();
    func_02055c48(1);
}
