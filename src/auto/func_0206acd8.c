/* Reconstructed from USA ARM9 at 0x0206acd8 (228 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02053f44(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02053f60(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0206af28(void *);                      /* extern */
extern M2C_UNK data_02101b78;

void func_0206acd8(void *arg0) {
    s16 temp_r0;

    if ((M2C_FIELD(arg0, u8 *, 8) != 0) && (M2C_FIELD(arg0, u8 *, 7) != 0)) {
        func_02053f60(&data_02101b78, 0x200);
        if (M2C_FIELD(arg0, u8 *, 6) != 0) {
            temp_r0                      = M2C_FIELD(arg0, s16 *, 0xC);
            M2C_FIELD(arg0, s16 *, 0xC)  = (s16) (temp_r0 + 5);
            M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0x10) - 5);
            if ((s32) M2C_FIELD(arg0, s16 *, 0xC) >= 0x1B) {
                M2C_FIELD(arg0, s16 *, 0xC)  = 0x1B;
                M2C_FIELD(arg0, s16 *, 0x10) = 0xA5;
                M2C_FIELD(arg0, u8 *, 7)     = 0U;
            }
            func_0206af28(arg0);
            return;
        }
        temp_r0                      = M2C_FIELD(arg0, s16 *, 0xC);
        M2C_FIELD(arg0, s16 *, 0xC)  = (s16) (temp_r0 - 5);
        M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0x10) + 5);
        if ((s32) M2C_FIELD(arg0, s16 *, 0xC) <= 0) {
            M2C_FIELD(arg0, s16 *, 0xA)  = 0;
            M2C_FIELD(arg0, s16 *, 0xC)  = 0;
            M2C_FIELD(arg0, s16 *, 0xE)  = 0xFF;
            M2C_FIELD(arg0, s16 *, 0x10) = 0xBF;
            M2C_FIELD(arg0, u8 *, 7)     = 0U;
            func_0206af28(arg0);
            func_02053f44(&data_02101b78, 0x200);
            return;
        }
        func_0206af28(arg0);
    }
}
