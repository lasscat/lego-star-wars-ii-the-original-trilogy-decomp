/* Reconstructed from USA ARM9 at 0x02005428 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* Link this reference into the chain at object+4, or clear its two links. */
void func_02005428(void *reference, void *object) {
    s8 *object_link = (s8 *) object;
    if (object_link != NULL) {
        object_link += 4;
    }
    if (object_link != NULL) {
        M2C_FIELD(reference, void **, 0)   = object_link;
        M2C_FIELD(reference, void **, 4)   = M2C_FIELD(object_link, void **, 0);
        M2C_FIELD(object_link, void **, 0) = reference;
    } else {
        M2C_FIELD(reference, void **, 0) = NULL;
        M2C_FIELD(reference, void **, 4) = NULL;
    }
}
