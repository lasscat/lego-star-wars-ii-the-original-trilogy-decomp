/* Reconstructed from USA ARM9 at 0x02086740 (100 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02086204(M2C_UNK, M2C_UNK);                /* extern */
s32 func_0208671c();                                /* extern */

s32 func_02086740(M2C_UNK arg0, s32 arg1) {
    if (func_0208671c() == 0) {
        goto ret0;
    }
    if (arg1 <= 0) {
        if (arg1 != 0) {
            goto ret1;
        }
    } else if ((arg1 <= 0x10) && (arg1 >= 0xD)) {
        if ((arg1 != 0xD) && (arg1 != 0xE) && (arg1 != 0x10)) {
            goto ret1;
        }
    } else {
        goto ret1;
    }
    return func_02086204(arg0, 0xA);
ret1:
    return 1;
ret0:
    return 0;
}
