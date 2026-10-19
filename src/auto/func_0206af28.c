#include "m2c.h"

void *func_020aaeb4();                              /* extern */
extern M2C_UNK NNS_G3dGlb;

s32 func_0206af28(void *arg0) {
    s32 temp_r5;
    s16 temp_r6;
    s32 temp_r7;
    s16 temp_r8;
    void *temp_r0;

    temp_r7                          = 0xBF - M2C_FIELD(arg0, s16 *, 0xC);
    temp_r5                          = 0xBF - M2C_FIELD(arg0, s16 *, 0x10);
    temp_r8                          = M2C_FIELD(arg0, s16 *, 0xE);
    temp_r6                          = M2C_FIELD(arg0, s16 *, 0xA);
    temp_r0                          = func_020aaeb4();
    M2C_FIELD(temp_r0, s32 *, 0x1B4) = temp_r5;
    M2C_FIELD(temp_r0, s32 *, 0x1B8) = (s32) temp_r6;
    M2C_FIELD(temp_r0, s32 *, 0x1BC) = temp_r7;
    M2C_FIELD(temp_r0, s32 *, 0x1C0) = (s32) temp_r8;
    M2C_FIELD(temp_r0, s32 *, 0x1AC) = M2C_FIELD(temp_r0, s32 *, 0x1AC) | 4;
    M2C_FIELD(temp_r0, s32 *, 0x1AC) = M2C_FIELD(temp_r0, s32 *, 0x1AC) & ~1;
    M2C_FIELD(temp_r0, s32 *, 0x1AC) = M2C_FIELD(temp_r0, s32 *, 0x1AC) | 1;
    return M2C_FIELD(&NNS_G3dGlb, s32 *, 0xA0) =
               (s32) (M2C_FIELD(arg0, s16 *, 0xA) | ((0xBF - M2C_FIELD(arg0, s16 *, 0x10)) << 8) |
                      (M2C_FIELD(arg0, s16 *, 0xE) << 0x10) | ((0xBF - M2C_FIELD(arg0, s16 *, 0xC)) << 0x18));
}
