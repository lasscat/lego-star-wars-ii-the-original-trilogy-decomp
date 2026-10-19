/* Reconstructed from USA ARM9 at 0x020632b4 (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e6e0(u8 *, M2C_UNK, s32);          /* extern */
extern M2C_UNK data_02104364;

void func_020632b4(M2C_UNK arg0, s32 arg1) {
    u8 *p;
    if ((s32) M2C_FIELD(&data_02104364, s32 *, 0x54) > 0) {
        *M2C_FIELD(&data_02104364, u8 **, 0x50) &= 0xFF >> (8 - M2C_FIELD(&data_02104364, s32 *, 0x54));
        M2C_FIELD(&data_02104364, u8 **, 0x50) = (u8 *) (M2C_FIELD(&data_02104364, u8 **, 0x50) + 1);
        M2C_FIELD(&data_02104364, s32 *, 0x54) = 0;
    }
    func_0205e6e0(M2C_FIELD(&data_02104364, u8 **, 0x50), arg0, arg1);
    p                                      = M2C_FIELD(&data_02104364, u8 **, 0x50);
    p                                      = p + arg1;
    M2C_FIELD(&data_02104364, u8 **, 0x50) = p;
}
