/* Reconstructed from USA ARM9 at 0x020846c0 (188 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02053f60(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02053f80(M2C_UNK *);                   /* extern */
M2C_UNK func_0205e860(s32);                         /* extern */
M2C_UNK func_02060694(void *);                      /* extern */
M2C_UNK func_0208562c(M2C_UNK *);                   /* extern */
M2C_UNK func_0208c628(M2C_UNK *);                   /* extern */
M2C_UNK func_020b9204();                            /* extern */
M2C_UNK func_020cef04(M2C_UNK);                     /* extern */
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02101b98;
extern M2C_UNK data_02104d94;
extern M2C_UNK data_02104dc4;
extern s32 data_027e02a4;

void func_020846c0(void *arg0) {
    u32 var_r4;
    void *var_r5;

    if (M2C_FIELD(arg0, u8 *, 0xEB9) != 0) {
        func_020cef04(2);
        M2C_FIELD(arg0, u8 *, 0xEB9) = 0U;
    }
    func_02060694(arg0 + 0x30);
    func_0205e860(M2C_FIELD(arg0, s32 *, 0xD08));
    func_02053f80(&data_02101b98);
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_02053f60(&data_02101b98, 0x2000);
    func_02053f80(&data_02101b78);
    func_020b9204();
    if (M2C_FIELD(arg0, u8 *, 0xEBA) != 0) {
        return;
    }
    var_r5 = &data_02104d94;
    var_r4 = 0;
    do {
        func_0208562c(var_r5);
        var_r4 += 1;
        var_r5 += 0xC;
    } while (var_r4 < 4U);
    func_0208c628(&data_02104dc4);
}
