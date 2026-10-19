/* Reconstructed from USA ARM9 at 0x020c4234 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK NNS_G3dGeBufferOP_N(s32, void *, M2C_UNK);        /* extern */
extern M2C_UNK NNS_G3dGlb;

void func_020c4234(void) {
    NNS_G3dGeBufferOP_N(*(s32 *) &NNS_G3dGlb, (s32 *) &NNS_G3dGlb + 1, 0x3E);
    M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & ~1);
    M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & ~2);
}
