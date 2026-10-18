/* Reconstructed from USA ARM9 at 0x02033770 (152 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02004b68(void *, M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK func_020675d8(s32, u8);                     /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */
extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_0210930c;

void func_02033770(void *arg0) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r2;

    temp_r0 = M2C_FIELD(arg0, void **, 4);
    temp_r2 = temp_r0 + 0x60;
    if (temp_r2 != &data_020ff9b4) {
        M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
    temp_r0_2                  = M2C_FIELD(arg0, void **, 4);
    func_02004b68(temp_r0_2, 1, temp_r0_2, 2);
    func_0206763c(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                  M2C_FIELD(arg0, u8 *, 0x2E));
    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                  M2C_FIELD(arg0, u8 *, 0x2D));
}
