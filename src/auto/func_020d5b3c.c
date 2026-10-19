#include "m2c.h"

M2C_UNK func_020d5770(M2C_UNK, M2C_UNK);            /* extern */

s32 func_020d5b3c(void) {
    volatile u32 *reg = (volatile u32 *) 0x040001A4;
    u32 v;

    func_020d5770(0xB8000000, 0);
    v    = *(volatile u32 *) 0x027FFE60;
    *reg = ((v & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    do {
    } while (!(*reg & 0x800000));
    return *(volatile u32 *) 0x04100010;
}
