#include "m2c.h"

M2C_UNK func_020cf1f0(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_020cf27c(void *, s32, M2C_UNK);        /* extern */
extern s32 data_027e038c;
extern s32 data_027e0390;

void func_020606c8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xC34) == 0) {
        return;
    }
    func_020cf27c(arg0 + 0x24, data_027e0390, 0xC00);
    func_020cf1f0(arg0 + 0x24, data_027e038c, 0x10);
}
