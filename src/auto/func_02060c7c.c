/* Reconstructed from USA ARM9 at 0x02060c7c (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_021041bc;

void func_02060c7c(void) {
    s32 outer;
    u32 inner;
    u8 *base;

    func_0205e624(&data_021041bc, 0, 0x108);
    base = (u8 *) &data_021041bc;
    for (outer = 0; outer < 2; outer++) {
        for (inner = 0; inner < 0x10; inner++) {
            base[inner * 8 + 4] = 0xFF;
        }
        base += 0x84;
    }
}
