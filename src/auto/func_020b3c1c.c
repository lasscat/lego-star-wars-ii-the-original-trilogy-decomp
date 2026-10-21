#include "m2c.h"

extern void *data_0210daf0;
extern void *data_0210daf4[];

M2C_UNK func_020b462c(s32);                         /* extern */

void func_020b3c1c(void) {
    s32 var_r5;
    void *temp_r2;
    void *temp_r3;

    for (var_r5 = 0; var_r5 < 3; var_r5++) {
        temp_r2 = data_0210daf4[var_r5 + 2];
        if ((temp_r2 != NULL) && (M2C_FIELD(temp_r2, u8 *, 0x25) == 1)) {
            data_0210daf0                   = temp_r2;
            M2C_FIELD(temp_r2, s16 *, 0x20) = (s16) (M2C_FIELD(temp_r2, s16 *, 0x20) - M2C_FIELD(temp_r2, u8 *, 0x2B));
            while (((temp_r3 = data_0210daf0) != NULL) && ((s32) M2C_FIELD(temp_r3, volatile s16 *, 0x20) <= 0)) {
                M2C_FIELD(temp_r3, volatile s16 *, 0x20) = (s16) (M2C_FIELD(temp_r3, volatile s16 *, 0x20) + 0x96);
                func_020b462c(var_r5);
            }
        }
    }
    data_0210daf0 = NULL;
}
