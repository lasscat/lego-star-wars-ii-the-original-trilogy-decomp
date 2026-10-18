/* Reconstructed from USA ARM9 at 0x0208580c (316 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02062e48(s32, M2C_UNK);                /* extern */
s32 func_0206ac84();                                /* extern */
s32 func_0207f488();                                /* extern */
M2C_UNK func_02085948(s32);                         /* extern */
M2C_UNK func_0208642c(s32);                         /* extern */
M2C_UNK func_0208d218(s32);                         /* extern */
s32 func_0209b61c();                                /* extern */
s32 func_020b0c74();                                /* extern */

void func_0208580c(s32 arg0) {
    s32 temp_r6;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    u8 var_ip;
    u8 var_lr;
    u8 var_r10;

    for (var_ip = 0; var_ip < 2; var_ip++) {
        for (var_lr = 0; var_lr < 3; var_lr++) {
            for (var_r10 = 0; var_r10 < 5; var_r10++) {
                M2C_FIELD((arg0 + (var_ip * 0x24) + (var_lr * 0xC) + (var_r10 * 2)), s16 *, 0x443E) = 0xFA;
            }
            M2C_FIELD((arg0 + (var_ip * 0x24) + (var_lr * 0xC)), s8 *, 0x4448) = 0x28;
        }
    }
    var_r0 = func_0205e80c(0xB4, 3, 4);
    if (var_r0 != 0) {
        var_r0 = func_0209b61c();
    }
    M2C_FIELD(arg0, s32 *, 0x2AD0) = var_r0;
    var_r0_2                       = func_0205e80c(0x14, 3, 4);
    if (var_r0_2 != 0) {
        var_r0_2 = func_0206ac84();
    }
    M2C_FIELD(arg0, s32 *, 0x2AD4) = var_r0_2;
    var_r0_3                       = func_0205e80c(0x14, 3, 4);
    if (var_r0_3 != 0) {
        var_r0_3 = func_020b0c74();
    }
    M2C_FIELD(arg0, s32 *, 0x2BB8) = var_r0_3;
    var_r0_4                       = func_0205e80c(0x40, 3, 4);
    if (var_r0_4 != 0) {
        var_r0_4 = func_0207f488();
    }
    M2C_FIELD(arg0, s32 *, 0x2AD8) = var_r0_4;
    M2C_FIELD(arg0, s8 *, 0x2BB4)  = 0;
    func_0208642c(arg0);
    func_02085948(arg0);
    func_02062e48(arg0 + 0x44AC, 3);
    func_0208d218(arg0 + 0x2BC0);
}
