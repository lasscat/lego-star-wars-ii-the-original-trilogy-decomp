#include "m2c.h"

void func_0201270c(void *arg0) {
    if (M2C_FIELD(arg0, void **, 0x1C4) == NULL) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x214) == 1) {
        M2C_FIELD(arg0, u16 *, 0x14E) = (u16) (M2C_FIELD(arg0, u16 *, 0x14E) & ~1);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C4), s8 *, 0x39C) = 0;
}
