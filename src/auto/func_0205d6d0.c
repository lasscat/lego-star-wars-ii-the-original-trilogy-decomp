/* Reconstructed from USA ARM9 at 0x0205d6d0 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u16 func_0205d6d0(void *arg0, void *arg1) {
    u16 count;

    count = 0;
    if (arg1 == NULL) {
        return 0;
    }
    do {
        count += 1;
        arg1 = M2C_FIELD(arg1, void **, 4);
    } while (arg1 != NULL);
    return count;
}
