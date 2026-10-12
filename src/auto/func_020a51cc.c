#include "m2c.h"

s32 func_02067b48(s32, u8);                         /* extern */

s32 func_020a51cc(void *arg0) {
    u8 temp_r2;
    u8 temp_r2_2;
    u8 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 0x2E8);
    if (temp_r3 != 0) {
        temp_r2_2 = M2C_FIELD(arg0, u8 *, 0x2E2);
        if ((u32) temp_r2_2 < (u32) M2C_FIELD(arg0, u8 *, 0x2E1)) {
            return func_02067b48(M2C_FIELD(arg0, s32 *, 0x21C), (u8) (temp_r2_2 + 1));
        }
    }
    if (temp_r3 == 0) {
        temp_r2 = M2C_FIELD(arg0, u8 *, 0x2E2);
        if ((u32) temp_r2 > (u32) M2C_FIELD(arg0, u8 *, 0x2E1)) {
            return func_02067b48(M2C_FIELD(arg0, s32 *, 0x21C), (u8) (temp_r2 - 1));
        }
    }
    return 0;
}
