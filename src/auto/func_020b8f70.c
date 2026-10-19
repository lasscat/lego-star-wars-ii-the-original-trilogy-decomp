/* Reconstructed from USA ARM9 at 0x020b8f70 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S0;

M2C_UNK func_020b8ecc(void *);
M2C_UNK func_020b8fa4(M2C_UNK, S0, s32);

void func_020b8f70(M2C_UNK arg0, s32 arg1) {
    S0 sp4;

    func_020b8ecc(&sp4);
    func_020b8fa4(arg0, sp4, arg1);
}
