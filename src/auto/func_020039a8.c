/* Reconstructed from USA ARM9 at 0x020039a8 (284 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020867ec(M2C_UNK *, M2C_UNK);              /* extern */
void *func_0208dad8();                              /* extern */
extern M2C_UNK data_020eebbb;
extern M2C_UNK data_020ef58a;
extern M2C_UNK data_02104d90;

u8 func_020039a8(void *arg0) {
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r2;
    u8 var_r4;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x6F4);
    var_r4  = 0xA;
    if (temp_r0 != 0xA) {
        return temp_r0;
    }
    temp_r2 = M2C_FIELD(arg0, u8 *, 0x6BB);
    if (((*((u16 *) ((s8 *) &data_020ef58a + (temp_r2 * 0x18))) != 0xB) &&
         ((M2C_FIELD(arg0, u16 *, 0x6EE) == *((u8 *) ((s8 *) &data_020eebbb + (temp_r2 * 5)))) ||
          (func_020867ec(&data_02104d90, 9) != 0) || (func_020867ec(&data_02104d90, 8) != 0) ||
          (func_020867ec(&data_02104d90, 7) != 0) || (func_020867ec(&data_02104d90, 0x13) != 0))) ||
        ((temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x6BB), ((u32) temp_r0_2 >= 0x50U)) && ((u32) temp_r0_2 <= 0x53U))) {
        return (u8) * ((u16 *) ((s8 *) &data_020ef58a + (M2C_FIELD(arg0, u8 *, 0x6BB) * 0x18)));
    }
    if (M2C_FIELD(arg0, u16 *, 0x6EE) != 0xFA) {
        var_r4 = M2C_FIELD(func_0208dad8(), u8 *, 0x26);
    }
    if ((var_r4 == 0xA) && (M2C_FIELD(arg0, u16 *, 0x6E8) != 0xFA)) {
        var_r4 = M2C_FIELD(func_0208dad8(), u8 *, 0x20);
    }
    return var_r4;
}
