/* Reconstructed from USA ARM9 at 0x020d0660 (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK PushCommand_impl(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */

void SND_SetupCapture(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5, s32 arg6) {
    PushCommand_impl(0x11, arg2, arg3, (arg0 << 0x1F) | (arg1 << 0x1E) | (arg4 << 0x1D) | (arg5 << 0x1C) | (arg6 << 0x1B), 0);
}
