/* Reconstructed from USA ARM9 at 0x02010954 (208 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02010954(void *arg0) {
    u8 temp_r1;
    u8 temp_r1_3;
    u8 temp_r1_4;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x1B2);
    switch (temp_r1) {
        case 0: {
            u32 t                        = M2C_FIELD(arg0, u8 *, 0x1AE) + M2C_FIELD(arg0, s8 *, 0x1AF);
            M2C_FIELD(arg0, u8 *, 0x1AE) = t;
            if ((t & 0xff) != 0 && (t & 0xff) != 0x1F) {
                M2C_FIELD(arg0, u8 *, 0x1B0) = M2C_FIELD(arg0, u8 *, 0x1B1);
                return;
            }
            M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) & ~0x20);
            return;
        }
        case 1:
            temp_r1_3 = M2C_FIELD(arg0, u8 *, 0x1AE);
            if (temp_r1_3 != 0) {
                M2C_FIELD(arg0, u8 *, 0x1AE) = (u8) (temp_r1_3 - 1);
                M2C_FIELD(arg0, u8 *, 0x1B0) = (u8) M2C_FIELD(arg0, u8 *, 0x1B1);
                return;
            }
            M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) & ~0x20);
            return;
        case 2:
            temp_r1_4 = M2C_FIELD(arg0, u8 *, 0x1AE);
            if (temp_r1_4 < 0x10) {
                M2C_FIELD(arg0, s8 *, 0x1AF) = 1;
            } else if (temp_r1_4 >= 0x1CU) {
                M2C_FIELD(arg0, s8 *, 0x1AF) = -1;
            }
            M2C_FIELD(arg0, u8 *, 0x1B0) = (u8) M2C_FIELD(arg0, u8 *, 0x1B1);
            M2C_FIELD(arg0, u8 *, 0x1AE) = (u8) (M2C_FIELD(arg0, u8 *, 0x1AE) + M2C_FIELD(arg0, s8 *, 0x1AF));
            return;
    }
}
