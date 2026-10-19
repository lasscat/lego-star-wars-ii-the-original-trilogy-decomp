#include "m2c.h"

M2C_UNK func_0206d6cc(void *);                      /* extern */
M2C_UNK func_0206d7cc(void *, u16);                 /* extern */
M2C_UNK func_0206d7fc(void *, M2C_UNK);             /* extern */

void func_0206d610(void *arg0) {
    if ((M2C_FIELD(arg0, u16 *, 0x22) != 0) && (M2C_FIELD(arg0, u16 *, 0x22) != 3)) {
        M2C_FIELD(arg0, u16 *, 0x2A) = (u16) (M2C_FIELD(arg0, u16 *, 0x2A) - 1);
        if (M2C_FIELD(arg0, u16 *, 0x2A) == 0) {
            M2C_FIELD(arg0, u16 *, 0x2A) = 1U;
            if (M2C_FIELD(arg0, u16 *, 0x22) == 1) {
                if ((u32) M2C_FIELD(arg0, u16 *, 0x28) < 9U) {
                    M2C_FIELD(arg0, u16 *, 0x28) = (u16) (M2C_FIELD(arg0, u16 *, 0x28) + 1);
                } else {
                    M2C_FIELD(arg0, u16 *, 0x22) = 3U;
                }
            } else if (M2C_FIELD(arg0, u16 *, 0x28) != 0) {
                M2C_FIELD(arg0, u16 *, 0x28) = (u16) (M2C_FIELD(arg0, u16 *, 0x28) - 1);
            } else {
                M2C_FIELD(arg0, u16 *, 0x22) = 3U;
            }
            func_0206d7cc(arg0, M2C_FIELD(arg0, u16 *, 0x28));
        }
        if (M2C_FIELD(arg0, u16 *, 0x22) != 3) {
            return;
        }
        func_0206d6cc(arg0);
        if (M2C_FIELD(arg0, u8 *, 0x20) == 0) {
            return;
        }
        func_0206d7fc(arg0, 1);
    }
}
