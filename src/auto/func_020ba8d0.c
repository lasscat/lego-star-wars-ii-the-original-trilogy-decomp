/* Reconstructed from USA ARM9 at 0x020ba8d0 (120 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S3;

M2C_UNK func_020b8ecc(M2C_UNK *);           /* extern */
u8 func_020ba9f0(u16, S3);                  /* extern */
extern M2C_UNK data_0210e0b4;

void func_020ba8d0(s32 arg0) {
    S3 sp0;
    M2C_UNK *var_r4;
    s32 var_r1;

    if (arg0 == 0xFFFF) {
        return;
    }
    var_r4 = &data_0210e0b4;
    var_r1 = 0x1F;
loop_3:
    if (M2C_FIELD(var_r4, u8 *, 2) == 0xFF) {
        M2C_FIELD(var_r4, u16 *, 0) = arg0;
        func_020b8ecc((M2C_UNK *) &sp0);
        M2C_FIELD(var_r4, u8 *, 2) = func_020ba9f0(arg0, sp0);
        return;
    }
    var_r4 -= 1;
    var_r1 -= 1;
    if (var_r1 < 0) {
        return;
    }
    goto loop_3;
}
