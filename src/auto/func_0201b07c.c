/* Reconstructed from USA ARM9 at 0x0201b07c (384 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0205ab44(u16);                             /* extern */

void func_0201b07c(void *arg0) {
    s32 temp_r0;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 temp_r5_4;
    s32 var_ip;
    s8 var_lr;
    s8 var_lr_2;
    u32 temp_lr_2;
    u8 temp_lr;
    void *var_r5;

    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x10000);
    temp_r0                   = func_0205ab44(M2C_FIELD(arg0, u16 *, 0x1E));
    var_r5                    = temp_r0 + (M2C_FIELD(arg0, s32 *, 0x24) * 2);
    func_0205ab44(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 2));
    var_ip = 1;
    do {
        temp_lr = M2C_FIELD(var_r5, u8 *, 0);
        if ((u32) temp_lr < 0xF1U) {
            M2C_FIELD(arg0, u8 *, 0x1B) = temp_lr;
            var_ip                      = 0;
            M2C_FIELD(arg0, u8 *, 0x18) = (u8) M2C_FIELD(var_r5, u8 *, 1);
        } else {
            temp_lr_2 = temp_lr - 0xF5;
            switch (temp_lr_2) {
                default:
                    break;
                case 10:
                    var_ip                    = 0;
                    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x10000);
                    break;
                case 9:
                    M2C_FIELD(arg0, u8 *, 0x18) = 1U;
                    var_ip                      = 0;
                    break;
                case 8:
                    temp_r5                      = M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(var_r5, u8 *, 1);
                    M2C_FIELD(arg0, s32 *, 0x24) = temp_r5;
                    var_r5                       = temp_r0 + (temp_r5 * 2);
                    break;
                case 7:
                    if (((u32) (M2C_FIELD(arg0, s32 *, 0x10) * 8) >> 0x1F) == 0) {
                        var_lr = (s8) M2C_FIELD(var_r5, u8 *, 1);
                    } else {
                        var_lr = 0 - M2C_FIELD(var_r5, u8 *, 1);
                    }
                    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (M2C_FIELD(arg0, s32 *, 0x54) + (var_lr << 0x10));
                    temp_r5_2                    = M2C_FIELD(arg0, s32 *, 0x24) + 1;
                    M2C_FIELD(arg0, s32 *, 0x24) = temp_r5_2;
                    var_r5                       = temp_r0 + (temp_r5_2 * 2);
                    break;
                case 6:
                    if (((u32) (M2C_FIELD(arg0, s32 *, 0x10) * 4) >> 0x1F) == 0) {
                        var_lr_2 = (s8) M2C_FIELD(var_r5, u8 *, 1);
                    } else {
                        var_lr_2 = 0 - M2C_FIELD(var_r5, u8 *, 1);
                    }
                    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + (var_lr_2 << 0x10));
                    temp_r5_3                    = M2C_FIELD(arg0, s32 *, 0x24) + 1;
                    M2C_FIELD(arg0, s32 *, 0x24) = temp_r5_3;
                    var_r5                       = temp_r0 + (temp_r5_3 * 2);
                    break;
                case 1:
                    temp_r5_4                    = M2C_FIELD(arg0, s32 *, 0x24) + 1;
                    M2C_FIELD(arg0, s32 *, 0x24) = temp_r5_4;
                    var_r5                       = temp_r0 + (temp_r5_4 * 2);
                    break;
            }
        }
    } while (var_ip == 1);
}
