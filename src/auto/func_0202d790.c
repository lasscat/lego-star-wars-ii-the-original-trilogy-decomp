/* Reconstructed from USA ARM9 at 0x0202d790 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0202d790(void *arg0, char *arg1) {
    if (arg1 != NULL) {
        arg1 += 4;
    }
    if (arg1 != NULL) {
        *(void **) arg0                = arg1;
        *(void **) ((char *) arg0 + 4) = *(void **) arg1;
        *(void **) arg1                = arg0;
    } else {
        *(void **) arg0                = NULL;
        *(void **) ((char *) arg0 + 4) = NULL;
    }
}
