/* Reconstructed from USA ARM9 at 0x02090ae8 (308 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02018420(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_0201cdb8(void *, M2C_UNK);             /* extern */
M2C_UNK func_02055108(void *);                      /* extern */
M2C_UNK func_020556e0(M2C_UNK *);                   /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_0208d41c(void *);                      /* extern */
M2C_UNK func_02090f3c(void *, M2C_UNK, s32);        /* extern */
M2C_UNK func_0209100c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0209444c(void *, M2C_UNK);             /* extern */
M2C_UNK func_020966c4(void *);                      /* extern */
void *func_020acb18(void *, s32);                   /* extern */
M2C_UNK func_020c6240(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_02101ae4;
extern M2C_UNK data_027e0410;

void func_02090ae8(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r3;
    s32 var_r4;
    void *temp_r2;
    void *temp_r5;
    void *var_r0;

    var_r3 = 0;
    var_r4 = arg2;
    do {
        temp_r2                         = arg0 + var_r3;
        M2C_FIELD(temp_r2, s8 *, 0x92E) = -1;
        var_r3 += 1;
        M2C_FIELD(temp_r2, s8 *, 0x932) = 0;
    } while (var_r3 < 4);
    func_020966c4(arg0);
    func_02055108(arg0 + 0x1A0);
    func_020556e0(&data_027e0410);
    func_0209444c(arg0 + 0xA4, arg1);
    func_0208d41c(arg0 + 0x94);
    M2C_FIELD(arg0, s32 *, 0x70) = 0xF0;
    if (var_r4 == 0) {
        var_r4 += 1;
    }
    func_02090f3c(arg0, arg1, var_r4);
    func_0201cdb8(arg0 + 0x74, 0x210);
    M2C_FIELD(arg0, s32 *, 0x44) = func_02018420(&data_02101ae4, 0);
    var_r0                       = func_0205e80c(0x74, 0, 4);
    if (var_r0 != NULL) {
        var_r0 = func_020acb18(var_r0, 0x5A8);
    }
    M2C_FIELD(arg0, void **, 0x40) = var_r0;
    temp_r5                        = M2C_FIELD(var_r0, void **, 8);
    temp_r4                        = M2C_FIELD((temp_r5 + M2C_FIELD(temp_r5, u16 *, 0xE)), s32 *, 0xC);
    func_020c6240(temp_r5 + temp_r4, 0, 0x3F000000);
    func_020c6240(temp_r5 + temp_r4, 0, 0x1F0000);
    func_020c6240(temp_r5 + temp_r4, 0, 0xC0);
    func_020c6240(temp_r5 + temp_r4, 0, 0xF);
    func_0209100c(arg0, 1);
    M2C_FIELD(arg0, s8 *, 0x924) = 1;
}
