#include "m2c.h"

void func_02048038(void *arg0) {
    if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x5CE) & 0x800) && (M2C_FIELD(arg0, u8 *, 0xE) == 0)) {
        M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
        return;
    }
}
