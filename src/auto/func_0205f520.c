#include "m2c.h"

M2C_UNK func_0200f744(s32);                         /* extern */
M2C_UNK func_02053d50(void *);                      /* extern */
M2C_UNK func_02055c78(s32);                         /* extern */
M2C_UNK func_02060c18(s32);                         /* extern */
M2C_UNK func_020636d4(s32);                         /* extern */
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02101b78;
extern s32 data_027e02a4;

void func_0205f520(s32 arg0, s32 arg1) {
    data_027e02a4 = arg1;
    func_0200f744((arg1 * 0x38) + (s32) &data_021019f4);
    func_020636d4(arg1);
    func_02053d50((M2C_UNK *)((s8 *)&data_02101b78 + (arg1 << 5)));
    func_02055c78(arg1);
    func_02060c18(arg1);
}
