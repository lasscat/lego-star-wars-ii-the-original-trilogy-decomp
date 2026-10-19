/* Reconstructed from USA ARM9 at 0x02063680 (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(s8 *, M2C_UNK, M2C_UNK);      /* extern */
extern s8 data_021043c4[];

void func_02063680(void) {
    s32 j, i;
    s8 *p;

    func_0205e624(data_021043c4, 0, 0x64);
    p = data_021043c4;
    for (j = 0; j < 2; j++) {
        s8 *q;
        i = 0;
        q = p;
        do {
            *q = 3;
            q += 10;
            i += 1;
        } while (i < 5);
        p += 0x32;
    }
}
