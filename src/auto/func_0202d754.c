/* Reconstructed from USA ARM9 at 0x0202d754 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* Copy a reference and link it into the same object's chain, or clear both links. */
void func_0202d754(void *reference, s8 **source_reference) {
    s8 *object_link;

    object_link = *source_reference;
    if (object_link != 0) {
        object_link -= 4;
    }
    if (object_link != 0) {
        object_link += 4;
    }
    if (object_link != 0) {
        M2C_FIELD(reference, void **, 0)   = object_link;
        M2C_FIELD(reference, void **, 4)   = M2C_FIELD(object_link, void **, 0);
        M2C_FIELD(object_link, void **, 0) = reference;
    } else {
        M2C_FIELD(reference, void **, 0) = NULL;
        M2C_FIELD(reference, void **, 4) = NULL;
    }
}
