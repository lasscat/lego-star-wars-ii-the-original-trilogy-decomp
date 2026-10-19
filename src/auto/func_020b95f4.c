/* Reconstructed from USA ARM9 at 0x020b95f4 (248 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020b9360(u16);                             /* extern */
M2C_UNK func_020b938c(u16);                         /* extern */
extern u8 data_0210db20;
extern void *data_0210db30;

void *func_020b95f4(void *arg0, void *arg1, u16 arg2, void *arg3) {
    void *temp_r1;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    if ((u32) data_0210db20 > 0x19U) {
        return arg0;
    }
    M2C_FIELD(arg0, u16 *, 0x18)  = arg2;
    M2C_FIELD(arg0, u8 *, 0x1A)   = 0U;
    M2C_FIELD(arg0, s8 *, 0x1B)   = 0;
    M2C_FIELD(arg0, s32 *, 0x14)  = -1;
    M2C_FIELD(arg0, void **, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)  = 0;
    if (arg1 != NULL) {
        if (arg0 != arg1) {
            M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg1, s32 *, 0);
            M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg1, s32 *, 4);
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg1, s32 *, 8);
        }
    } else {
        temp_r1 = arg3 + 0xB0;
        if (arg0 != temp_r1) {
            M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(temp_r1, s32 *, 0);
            M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(temp_r1, s32 *, 4);
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(temp_r1, s32 *, 8);
        }
    }
    if (func_020b9360(arg2) != 0) {
        M2C_FIELD(arg0, u8 *, 0x1A) = (u8) (M2C_FIELD(arg0, u8 *, 0x1A) | 2);
        func_020b938c(M2C_FIELD(arg0, u16 *, 0x18));
        M2C_FIELD(arg0, u8 *, 0x1A) = (u8) (M2C_FIELD(arg0, u8 *, 0x1A) | 4);
    }
    M2C_FIELD(data_0210db30, M2C_UNK(**)(void **, void *), 8)(&data_0210db30, arg0);
    data_0210db20 += 1;
    return arg0;
}
