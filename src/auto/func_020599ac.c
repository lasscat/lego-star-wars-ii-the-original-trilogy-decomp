/* Reconstructed from USA ARM9 at 0x020599ac (96 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02086534(M2C_UNK *, u8);                   /* extern */
M2C_UNK func_02086458(M2C_UNK *);                   /* extern */
M2C_UNK func_02086558(M2C_UNK *);                   /* extern */
extern u8 data_020eedad;
extern M2C_UNK data_02104d90;

void func_020599ac(s32 arg0, u8 *arg1) {
    u8 temp_r0;
    u8 *p;

    if (func_02086534(&data_02104d90, *arg1) != 0) {
        return;
    }
    p = &data_020eedad;
    p += *arg1 * 0x14;
    temp_r0 = *p;
    if (temp_r0 == 1) {
        func_02086458(&data_02104d90);
        return;
    }
    if (temp_r0 == 0) {
        func_02086558(&data_02104d90);
        return;
    }
}
