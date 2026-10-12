#include "m2c.h"

M2C_UNK func_01ffc3d8();                            /* extern */
M2C_UNK func_01ffc45c(s32, s32 *, s32);             /* extern */
M2C_UNK func_020cf0b8(s32, s32 *, u32, M2C_UNK *, s32 *); /* extern */
extern s32 data_0210153c;
extern s32 data_027e0e78;
extern M2C_UNK func_01ffc450;

void func_020c5dfc(s32 *arg0, u32 arg1) {
    if ((arg1 < 0x100U) || (data_0210153c == -1)) {
        func_01ffc45c(*arg0, ((s8 *)arg0 + 4), (arg1 >> 2) - 1);
        return;
    }
    func_01ffc3d8();
    data_027e0e78 = 1;
    func_020cf0b8(data_0210153c, arg0, arg1, &func_01ffc450, &data_027e0e78);
}
