/* Reconstructed from USA ARM9 at 0x020962e8 (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x020962e8 (112 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

extern M2C_UNK data_020ff874;
extern s32 data_02109c70;

void func_020962e8(void *arg0) {
    s32 temp_r3;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff874;
    M2C_FIELD(arg0, s32 *, 4)      = 0;
    M2C_FIELD(arg0, s32 *, 8)      = 0;
    M2C_FIELD(arg0, s32 *, 0xC)    = 0;
    M2C_FIELD(arg0, s32 *, 0x10)   = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0x1000;
    M2C_FIELD(arg0, s8 *, 0x1C)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1D)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1E)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1F)    = 0;
    M2C_FIELD(arg0, u8 *, 0x20)    = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x21)    = 0;
    M2C_FIELD(arg0, s32 *, 0x28)   = 0;
    temp_r3                        = data_02109c70;
    data_02109c70                  = temp_r3 + 1;
    M2C_FIELD(arg0, s32 *, 0x24)   = temp_r3;
    M2C_FIELD(arg0, s8 *, 0x21)    = 0;
    M2C_FIELD(arg0, u8 *, 0x20)    = 0xFF;
}
