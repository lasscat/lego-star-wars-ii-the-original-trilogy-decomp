/* Reconstructed from USA ARM9 at 0x020b9360 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020ba86c(u16);                         /* extern */
extern M2C_UNK data_02100a76;
extern M2C_UNK data_02100d98;

void func_020b9360(s32 arg0) {
    u16 i = *(u16 *) ((s8 *) &data_02100a76 + (arg0 * 4));
    func_020ba86c(*(u16 *) ((s8 *) &data_02100d98 + (i * 4)));
}
