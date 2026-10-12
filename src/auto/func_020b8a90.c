#include "m2c.h"

M2C_UNK func_020b861c(M2C_UNK);                     /* extern */
extern void *data_0210daf0;

void func_020b8a90(void) {
    s32 temp_r1_2;
    s32 temp_r1_3;
    u8 temp_r1;
    u8 temp_r2;
    u8 temp_r3;

    temp_r3 = M2C_FIELD(data_0210daf0, u8 *, 0x38);
    if (temp_r3 == 0) {
        return;
    }
    temp_r2 = M2C_FIELD(data_0210daf0, u8 *, 0x37);
    temp_r1 = M2C_FIELD(data_0210daf0, u8 *, 0x36);
    if ((u32) temp_r1 > (u32) temp_r2) {
        temp_r1_2 = temp_r1 - temp_r3;
        if (temp_r1_2 > (s32) temp_r2) {
            M2C_FIELD(data_0210daf0, u8 *, 0x36) = (u8) temp_r1_2;
        } else {
            M2C_FIELD(data_0210daf0, u8 *, 0x36) = temp_r2;
            M2C_FIELD(data_0210daf0, u8 *, 0x38) = 0U;
        }
    } else if ((u32) temp_r1 < (u32) temp_r2) {
        temp_r1_3 = temp_r1 + temp_r3;
        if (temp_r1_3 < (s32) temp_r2) {
            M2C_FIELD(data_0210daf0, u8 *, 0x36) = (u8) temp_r1_3;
        } else {
            M2C_FIELD(data_0210daf0, u8 *, 0x36) = temp_r2;
            M2C_FIELD(data_0210daf0, u8 *, 0x38) = 0U;
        }
    } else {
        M2C_FIELD(data_0210daf0, u8 *, 0x38) = 0U;
    }
    func_020b861c(2);
}
