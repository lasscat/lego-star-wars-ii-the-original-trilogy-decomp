/* Reconstructed from USA ARM9 at 0x0205d6a0 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0205d6a0(void *arg0, s32 arg1) {
    void *p   = M2C_FIELD(arg0, void **, 4);
    void *ret = NULL;

    if (p == NULL) {
        return ret;
    }
    do {
        if (M2C_FIELD(p, s32 *, 0) == arg1) {
            ret = p;
            break;
        }
        p = M2C_FIELD(p, void **, 4);
    } while (p != NULL);
    return ret;
}
