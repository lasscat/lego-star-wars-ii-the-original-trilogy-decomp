/* Reconstructed from USA ARM9 at 0x02072f04 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 data_02104d34[];
void func_02072f04(void) {
    s32 i = 0;
    do {
        if (data_02104d34[i] != 0) {
            data_02104d34[i] = 0;
        }
        i += 1;
    } while (i < 3);
}
