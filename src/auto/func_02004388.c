#include "m2c.h"

M2C_UNK func_0200c38c(void *);                      /* extern */
M2C_UNK func_0200c440();                            /* extern */
M2C_UNK func_0200c66c();                            /* extern */
M2C_UNK func_02010644(void *);                      /* extern */

void func_02004388(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x1A8) & 8) {
        M2C_FIELD(arg0, s32 *, 0xF4) = (s32) (M2C_FIELD(arg0, s32 *, 0xF4) | 4);
        M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) & ~8);
        func_0200c66c(arg0);
        func_02010644(arg0);
        func_0200c38c(arg0);
        M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) | 8);
        M2C_FIELD(arg0, s32 *, 0xF4) = (s32) (M2C_FIELD(arg0, s32 *, 0xF4) & ~4);
        return;
    }
    func_0200c440(arg0);
}
