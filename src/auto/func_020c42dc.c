/* Reconstructed from USA ARM9 at 0x020c42dc (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Blk;

typedef struct {
    u8 pad[0xFC];
    s32 fc;
} G;

extern G NNS_G3dGlb;
extern M2C_UNK data_027e0cf4;

void func_020c42dc(Blk *arg0) {
    *(Blk *) &data_027e0cf4 = *arg0;
    NNS_G3dGlb.fc &= ~0xA4;
}
