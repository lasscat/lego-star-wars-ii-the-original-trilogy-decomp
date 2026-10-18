/* Reconstructed from USA ARM9 at 0x020c4304 (40 bytes).
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

extern G data_027e0c14;
extern M2C_UNK data_027e0d00;

void func_020c4304(Blk *arg0) {
    *(Blk *) &data_027e0d00 = *arg0;
    data_027e0c14.fc &= ~0xA4;
}
