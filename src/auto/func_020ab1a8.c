/* Reconstructed from USA ARM9 at 0x020ab1a8 (144 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205ab6c();                         /* extern */
M2C_UNK func_02064fb8();                            /* extern */
M2C_UNK func_020ab614();              /* extern */
M2C_UNK func_020abc00();           /* extern */
extern M2C_UNK data_0210a07c;

void func_020ab1a8(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    if ((temp_r0 != NULL) && (M2C_FIELD(temp_r0, u8 *, 0xC) & 8)) {
        func_02064fb8(temp_r0);
    }
    func_020ab614(arg0, arg0 + 8);
    func_0205ab6c(M2C_FIELD(arg0, u16 *, 0x10));
    if (M2C_FIELD(arg0, u16 *, 0x12) != 0xFFFF) {
        func_0205ab6c(M2C_FIELD(arg0, u16 *, 0x12));
        M2C_FIELD(arg0, u16 *, 0x14) = (u16) (M2C_FIELD(arg0, u16 *, 0x14) & ~4);
    }
    func_020abc00(&data_0210a07c, arg0);
    M2C_FIELD(arg0, s32 *, 0)    = 0;
    M2C_FIELD(arg0, s32 *, 4)    = 0;
    M2C_FIELD(arg0, void **, 8)  = NULL;
    M2C_FIELD(arg0, u16 *, 0x10) = 0xFFFFU;
    M2C_FIELD(arg0, u16 *, 0x12) = 0xFFFFU;
    M2C_FIELD(arg0, s32 *, 0xC)  = 0;
}
