/* Reconstructed from USA ARM9 at 0x02065458 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(u16 *, M2C_UNK, M2C_UNK);
extern u16 data_021047fc;
extern M2C_UNK data_020edc78;

void func_02065458(void) {
    u16 *src;
    u32 i;
    u16 *dst;

    func_0205e624(&data_021047fc, 0, 0x118);
    dst = &data_021047fc;
    src = (u16 *) &data_020edc78;
    i   = 0;
    for (; i < 5U; i++) {
        *dst = src[i * 4];
        dst  = (u16 *) ((s8 *) dst + 0x38);
    }
}
