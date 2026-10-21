#include "m2c.h"

void func_02059e4c(void *);

void func_02059e64(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 8) != 0) {
        func_02059e4c(arg0);
        return;
    }
    /* keep the previous mask, then rebuild the current one from zero */
    M2C_FIELD(arg0, u16 *, 2) = M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0) = 0;
    M2C_FIELD(arg0, u16 *, 0) |= (u16) arg1;
    /* bits that appeared / disappeared compared to the previous mask */
    M2C_FIELD(arg0, u16 *, 4) = M2C_FIELD(arg0, u16 *, 0) & (M2C_FIELD(arg0, u16 *, 0) ^ M2C_FIELD(arg0, u16 *, 2));
    M2C_FIELD(arg0, u16 *, 6) = M2C_FIELD(arg0, u16 *, 2) & (M2C_FIELD(arg0, u16 *, 0) ^ M2C_FIELD(arg0, u16 *, 2));
}
