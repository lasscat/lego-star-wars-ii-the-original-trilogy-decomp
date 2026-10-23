#include "m2c.h"

void func_0206574c(void *, s32, s32);                             /* extern */
M2C_UNK *func_02066708(M2C_UNK);                                  /* extern */
s32 func_02065be8(M2C_UNK, M2C_UNK, s32, s32, s32, s32);          /* extern */
void func_02064b3c(void *, s16 *, void *, M2C_UNK, s32);          /* extern */

void func_020743c4(void *arg0, s32 arg1) {
    s32 val  = 1;
    s32 i    = 0;
    s32 off  = 0x38;
    s32 *ptr = (s32 *) ((u8 *) arg0 + 0x74);

    while (i < 3) {
        if (i == arg1) {
            func_0206574c((void *) ((u8 *) arg0 + 0x40), 3, -2);
        } else {
            func_0206574c((void *) ((u8 *) arg0 + 0x40), 0, -2);
        }
        val = func_02065be8((M2C_UNK) ((u8 *) arg0 + 0x40), val, 0x80, off, func_02066708(i + 3), 1);
        if (M2C_FIELD(arg0, u8 *, 0xaa) == 0) {
            s16 pair[2];
            pair[0] = 0x80;
            pair[1] = off;
            func_02064b3c(ptr, pair, (void *) ((u8 *) arg0 + 0x40), i + 3, 1);
        }
        off += 0x20;
        ptr += 3;
        i++;
    }
    M2C_FIELD(arg0, u8 *, 0xaa) = 1;
}
