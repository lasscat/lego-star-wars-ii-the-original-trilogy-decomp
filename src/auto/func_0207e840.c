#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205ea38(s32, M2C_UNK);                /* extern */
M2C_UNK func_0207de1c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205e8d0(s32);                         /* extern */

void func_0207e840(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x3C), s32 *, 0x8) |= 2;
    }
    func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
    func_0205ea38((s32) ((s8 *) arg0 + 0x14), 0);
    M2C_FIELD(arg0, u8 *, 0x25) = 0;
    func_0205ea38((s32) ((s8 *) arg0 + 0x14), 0);
    func_0207de1c((s32) arg0, M2C_FIELD(arg0, u8 *, 0x25));
    M2C_FIELD(arg0, u8 *, 0x27) = 3;
    M2C_FIELD(arg0, u8 *, 0x26) = 0x10;
    func_0205e8d0((s32) ((s8 *) arg0 + 0x14));
}
