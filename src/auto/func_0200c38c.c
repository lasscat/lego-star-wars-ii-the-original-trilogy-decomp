/* Reconstructed from USA ARM9 at 0x0200c38c (180 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK NNS_G3dGeFlushBuffer();                            /* extern */
M2C_UNK MTX_Copy44To43_(M2C_UNK *, s32);              /* extern */
s32 G3X_GetClipMtx(M2C_UNK *);                       /* extern */
M2C_UNK func_020cf528(M2C_UNK *);                   /* extern */
extern M2C_UNK data_027e02bc;

void func_0200c38c(void *arg0) {
    u8 sp0[64];
    u32 var_r5;
    s32 var_r6;
    void *var_r7;

    var_r7 = arg0;
    NNS_G3dGeFlushBuffer();
    var_r5                                      = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 0)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 4)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 0x14) = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 0)    = 2;
    var_r6                                      = var_r7 + 0x39C;
    do {
        if (M2C_FIELD(var_r7, u8 *, 0x3CD) != 0) {
            M2C_FIELD(var_r7, s8 *, 0x3CC)              = 1;
            M2C_FIELD((void *) 0x04000440, s32 *, 0x10) = (s32) M2C_FIELD(var_r7, u8 *, 0x3CE);
            do {

            } while (G3X_GetClipMtx(sp0) != 0);
            MTX_Copy44To43_(sp0, var_r6);
        }
        var_r5 += 1;
        var_r7 += 0x38;
        var_r6 += 0x38;
    } while (var_r5 < 0xAU);
    M2C_FIELD((void *) 0x04000440, s32 *, 0) = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 8) = 1;
    M2C_FIELD((void *) 0x04000440, s32 *, 0) = 2;
    func_020cf528(&data_027e02bc);
}
