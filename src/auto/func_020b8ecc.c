/* Reconstructed from USA ARM9 at 0x020b8ecc (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(s8 *, M2C_UNK, M2C_UNK);      /* extern */

typedef struct {
    M2C_UNK a;
    M2C_UNK b;
    M2C_UNK c;
} S0;

void func_020b8ecc(void *arg0) {
    S0 sp0;

    func_0205e624((s8 *) &sp0, 0, 0xC);
    M2C_FIELD(&sp0, s8 *, 0) = 7;
    *(S0 *) arg0             = sp0;
}
