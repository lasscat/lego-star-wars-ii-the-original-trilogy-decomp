/* Reconstructed from USA ARM9 at 0x020682c4 (296 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020536a8(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205e874(void *, M2C_UNK);             /* extern */
M2C_UNK func_0206846c(void *);                      /* extern */
M2C_UNK func_02068d74(void *);                      /* extern */
M2C_UNK func_020691b4(void *, M2C_UNK);             /* extern */
s32 func_02086204(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fe790;
extern M2C_UNK data_02104d90;

void *func_020682c4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6) {
    u32 temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe77c;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s16 *, 8)      = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe790;
    func_0205e874(arg0 + 0xC, 0x20);
    M2C_FIELD(arg0, s32 *, 0x14) = arg3;
    M2C_FIELD(arg0, s32 *, 0x18) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1C) = arg4;
    M2C_FIELD(arg0, u32 *, 0x20) = 0U;
    M2C_FIELD(arg0, u32 *, 0x24) = 0U;
    M2C_FIELD(arg0, u32 *, 0x28) = 0xCU;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, u8 *, 0x34)  = arg6;
    M2C_FIELD(arg0, u8 *, 0x35)  = 0U;
    M2C_FIELD(arg0, s8 *, 0x37)  = (s8) arg5;
    M2C_FIELD(arg0, u8 *, 0x36)  = 0xFF;
    if (arg6 == 1) {
        M2C_FIELD(arg0, u32 *, 0x24) = 0xCU;
        M2C_FIELD(arg0, u32 *, 0x28) = 0xEU;
    }
    temp_r2 = M2C_FIELD(arg0, u32 *, 0x24);
    if (((u32) M2C_FIELD(&data_02104d90, s8 *, 0x51) >= temp_r2) &&
        ((u32) M2C_FIELD(&data_02104d90, s8 *, 0x51) < (u32) M2C_FIELD(arg0, u32 *, 0x28))) {
        M2C_FIELD(arg0, u32 *, 0x20) = (u32) M2C_FIELD(&data_02104d90, s8 *, 0x51);
    } else {
        M2C_FIELD(arg0, u32 *, 0x20) = temp_r2;
    }
    if (func_02086204(&data_02104d90, 0xA) == 0) {
        M2C_FIELD(arg0, u8 *, 0x35) = 1U;
    }
    func_0206846c(arg0);
    if (M2C_FIELD(arg0, u8 *, 0x35) != 0) {
        M2C_FIELD(arg0, s8 *, 0x30) = 0x64;
        M2C_FIELD(arg0, s8 *, 0x31) = 0x64;
        M2C_FIELD(arg0, s8 *, 0x32) = 0x64;
        M2C_FIELD(arg0, s8 *, 0x33) = 0x64;
        func_020691b4(arg0, 1);
    }
    func_02068d74(arg0);
    func_020536a8(M2C_FIELD(arg0, s32 *, 0x18), 1);
    return arg0;
}
