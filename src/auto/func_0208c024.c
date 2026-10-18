/* Reconstructed from USA ARM9 at 0x0208c024 (156 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0208b54c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0208b76c(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_0208c0c0(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_02108d90;

void func_0208c024(void *arg0, s32 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, u8 *, 0x88) = 0xFF;
    if (arg1 != 0x10) {
        if (arg1 == 0x54) {
            M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) | 0x20);
            M2C_FIELD(arg0, s8 *, 0x86)  = arg2;
            M2C_FIELD(arg0, s8 *, 0x87)  = arg3;
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) M2C_FIELD(&data_02108d90, s32 *, 0x4C8);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) | 0x40);
        M2C_FIELD(arg0, s8 *, 0x86)  = arg2;
        M2C_FIELD(arg0, s8 *, 0x87)  = arg3;
    }
    if (arg1 == 0x64) {
        return;
    }
    func_0208b54c(arg0, 0);
    func_0208b76c(arg0, arg1, 1);
    if (arg1 != 0x54) {
        return;
    }
    func_0208c0c0(arg0, 1);
}
