/* Reconstructed from USA ARM9 at 0x020367b8 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* Link this reference into the chain at object+4, or clear its two links. */
void func_020367b8(void *reference, char *object) {
    if (object != NULL) {
        object += 4;
    }
    if (object != NULL) {
        *(void **) reference                = object;
        *(void **) ((char *) reference + 4) = *(void **) object;
        *(void **) object                   = reference;
    } else {
        *(void **) reference                = NULL;
        *(void **) ((char *) reference + 4) = NULL;
    }
}
