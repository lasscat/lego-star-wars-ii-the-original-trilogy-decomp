/* Reconstructed from USA ARM9 at 0x020469d0 (340 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02046d00(void *, u8);                  /* extern */
extern M2C_UNK data_020ed2ec;
extern M2C_UNK data_020ed2f1;
extern M2C_UNK data_020ed2f2;
extern M2C_UNK data_020ed2f3;
extern M2C_UNK data_020ed2f4;
extern M2C_UNK data_020ed2f5;

void func_020469d0(void *arg0) {
    M2C_UNK (*temp_r2_3)(void *, M2C_UNK);
    u8 temp_r2;
    u8 temp_r2_2;
    u8 temp_r3;
    void *temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x1C) == 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x5D2) & 2) {
        func_02046d00(arg0, *((u8 *) ((s8 *) &data_020ed2f3 + (M2C_FIELD(arg0, u8 *, 0x16) * 0x10))));
    }
    temp_r1 = M2C_FIELD(arg0, void **, 4);
    if ((M2C_FIELD(temp_r1, u16 *, 0x5D2) & 0x800) && !(M2C_FIELD(temp_r1, u8 *, 0x6C4) & 3) &&
        ((temp_r2 = M2C_FIELD(arg0, u8 *, 0x16), temp_r3 = *((u8 *) ((s8 *) &data_020ed2f1 + (temp_r2 * 0x10))),
          (temp_r3 == 0)) ||
         (((u32) (M2C_FIELD(temp_r1, u16 *, 0x186) << 0x1D) >> 0x1F) != 0))) {
        if (temp_r3 != 0) {
            M2C_FIELD(arg0, u8 *, 0x1A) = 1U;
        } else {
            func_02046d00(arg0, *((u8 *) ((s8 *) &data_020ed2f4 + (temp_r2 * 0x10))));
        }
    }
    if (((u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x14E) << 0x1E) >> 0x1F) == 1) {
        temp_r2_2 = M2C_FIELD(arg0, u8 *, 0x16);
        if (*((u8 *) ((s8 *) &data_020ed2f2 + (temp_r2_2 * 0x10))) == 0) {
            func_02046d00(arg0, *((u8 *) ((s8 *) &data_020ed2f5 + (temp_r2_2 * 0x10))));
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 0x1A) != 0) &&
        (((u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x186) << 0x1C) >> 0x1F) != 0)) {
        func_02046d00(arg0, *((u8 *) ((s8 *) &data_020ed2f4 + (M2C_FIELD(arg0, u8 *, 0x16) * 0x10))));
    }
    temp_r2_3 = *(M2C_UNK(**)(void *, M2C_UNK))((s8 *) &data_020ed2ec + (M2C_FIELD(arg0, u8 *, 0x16) * 0x10));
    if (temp_r2_3 == NULL) {
        return;
    }
    temp_r2_3(arg0, 0);
}
