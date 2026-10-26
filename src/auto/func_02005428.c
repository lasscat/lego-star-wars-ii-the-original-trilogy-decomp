/* Reconstructed from USA ARM9 at 0x02005428 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* Link this reference into the chain at object+4, or clear its two links. */
void func_02005428(void *arg0, void *arg1) {
    s8 *p = (s8 *) arg1;
    if (p != NULL) {
        p += 4;
    }
    if (p != NULL) {
        M2C_FIELD(arg0, void **, 0) = p;
        M2C_FIELD(arg0, void **, 4) = M2C_FIELD(p, void **, 0);
        M2C_FIELD(p, void **, 0)    = arg0;
    } else {
        M2C_FIELD(arg0, void **, 0) = NULL;
        M2C_FIELD(arg0, void **, 4) = NULL;
    }
}
