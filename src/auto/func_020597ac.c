#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_020597ac(M2C_UNK arg0, void *arg1) {
    u8 *base;
    void *temp_r0;
    s32 i;
    s32 cond;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (M2C_FIELD(temp_r0, u16 *, 0xC) != 4) {
        return;
    }
    base = (u8 *) temp_r0;
    i    = 1;
loop:
    if ((base[i * 2 + 0x1DE] == 0xFF) || (base[i * 2 + 0x1DF] == 0)) {
        cond = 0;
    } else {
        cond = 1;
    }
    if (cond == 0) {
        base[i * 2 + 0x1DE] = base[0x88];
        base[i * 2 + 0x1DF] = base[0x89];
    } else {
        i++;
        if (i < 0x19) {
            goto loop;
        }
    }
    base[0x1DC]++;
}
