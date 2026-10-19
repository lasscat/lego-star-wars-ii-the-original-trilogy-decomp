/* Reconstructed from USA ARM9 at 0x020a95d4 (96 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020ff9b4;

void func_020a95d4(void *arg0, s8 arg1, s32 arg2) {
    volatile s16 sp2;
    volatile s16 sp0;

    M2C_FIELD(arg0, s8 *, 0x30C) = arg1;
    if ((arg0 + 0x310) != &data_020ff9b4) {
        M2C_FIELD(arg0, s32 *, 0x310) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x314) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x318) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(arg0, s32 *, 0x200) = 0;
    M2C_FIELD(arg0, s16 *, 0x31C) = 0;
    sp2                           = 0;
    sp0                           = 0;
    M2C_FIELD(arg0, s32 *, 0x204) = arg2;
}
