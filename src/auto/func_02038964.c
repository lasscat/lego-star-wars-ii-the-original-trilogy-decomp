/* Reconstructed from USA ARM9 at 0x02038964 (176 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020931b0(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_0210930c;

void func_02038964(void *arg0) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r2;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r0                    = M2C_FIELD(arg0, void **, 4);
    temp_r2                    = temp_r0 + 0x60;
    if (temp_r2 != &data_020ff9b4) {
        M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x1AD) = 1;
    temp_r1                                             = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_r1, u16 *, 0xC) != 4) {
        return;
    }
    if (M2C_FIELD(temp_r1, u16 *, 0x212) != 0x129) {
        return;
    }
    temp_r0_2 = func_020931b0(&data_0210930c, 0x37);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, void **, 0x6AC) = (void *) M2C_FIELD(arg0, void **, 0x10);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x6BA) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x1AD) = 0;
    M2C_FIELD(arg0, u8 *, 0xC)                          = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
