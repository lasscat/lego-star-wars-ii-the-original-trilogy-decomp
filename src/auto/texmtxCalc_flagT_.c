#include "m2c.h"

void FX_DivAsync(s32, s32);
s32 func_020c930c(void);

/* Builds the "T" variant of the texture matrix from the source parameters.
 * The four products are 12.20-style fixed point multiplies done in 64 bits. */
void texmtxCalc_flagT_(void *arg0, void *arg1) {
    s32 e = M2C_FIELD(arg1, u16 *, 0x2c) << 12;
    s32 f = M2C_FIELD(arg1, u16 *, 0x2e) << 12;
    s32 m01, m00, m11, m10;

    FX_DivAsync(f, e);

    m01 = (s32) (((s64) M2C_FIELD(arg1, s32 *, 0x18) * M2C_FIELD(arg1, s16 *, 0x20)) >> 12);
    m00 = (s32) (((s64) M2C_FIELD(arg1, s32 *, 0x18) * M2C_FIELD(arg1, s16 *, 0x22)) >> 12);
    m11 = (s32) (((s64) M2C_FIELD(arg1, s32 *, 0x1c) * M2C_FIELD(arg1, s16 *, 0x20)) >> 12);
    m10 = (s32) (((s64) M2C_FIELD(arg1, s32 *, 0x1c) * M2C_FIELD(arg1, s16 *, 0x22)) >> 12);

    M2C_FIELD(arg0, s32 *, 0)    = m00;
    M2C_FIELD(arg0, s32 *, 0x14) = m10;
    M2C_FIELD(arg0, s32 *, 0x4)  = ((-m11) * func_020c930c()) >> 12;

    FX_DivAsync(e, f);

    M2C_FIELD(arg0, s32 *, 0x30) = ((M2C_FIELD(arg1, s32 *, 0x18) - (m01 + m00)) * M2C_FIELD(arg1, u16 *, 0x2c)) << 3;
    M2C_FIELD(arg0, s32 *, 0x34) = (((m11 - m10) - M2C_FIELD(arg1, s32 *, 0x1c) + 0x2000) * M2C_FIELD(arg1, u16 *, 0x2e)) << 3;

    M2C_FIELD(arg0, s32 *, 0x10) = (m01 * func_020c930c()) >> 12;
}
