/* Reconstructed from USA ARM9 at 0x0209f8d4 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205ab6c(u16);                         /* extern */
M2C_UNK func_020612d4(M2C_UNK *, u16, s32);         /* extern */
extern M2C_UNK data_027e03a0;

void func_0209f8d4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        func_020612d4(&data_027e03a0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), u16 *, 8), M2C_FIELD(arg0, s32 *, 0xB8));
        M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0xA0) != 0) {
        func_0205ab6c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), u16 *, 6));
        M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    }
    M2C_FIELD(arg0, void **, 0x9C) = NULL;
    M2C_FIELD(arg0, u16 *, 0xAE)   = 0xF5;
    M2C_FIELD(arg0, u8 *, 0xB0)    = 0xFF;
    M2C_FIELD(arg0, u8 *, 0xB1)    = 0;
}
