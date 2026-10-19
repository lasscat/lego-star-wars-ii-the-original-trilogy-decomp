#include "m2c.h"

M2C_UNK func_02053fc0(void *, s32);                 /* extern */
M2C_UNK func_0205401c(void *, s32);                 /* extern */
M2C_UNK func_02054080(void *, s32, s32);            /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02101b86;
extern M2C_UNK data_021043c4;

void func_02063868(s32 arg0, u32 arg1) {
    s32 temp_r3;

    temp_r3 = (arg1 * 0xA) + ((arg0 * 0x32) + (s32) &data_021043c4);
    switch (arg1) {
        return;
        case 0:
            func_02053fc0((M2C_UNK *) ((s8 *) &data_02101b78 + (arg0 << 5)), (s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8);
            return;
        case 1:
            func_0205401c((M2C_UNK *) ((s8 *) &data_02101b78 + (arg0 << 5)), (s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8);
            return;
        case 2:
            func_02054080((M2C_UNK *) ((s8 *) &data_02101b78 + (arg0 << 5)), (s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8,
                          0x10 - ((s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8));
            return;
        case 3:
            func_02054080((M2C_UNK *) ((s8 *) &data_02101b78 + (arg0 << 5)), (s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8,
                          (s32) * (u16 *) ((s8 *) &data_02101b86 + (arg0 << 5)) >> 8);
            return;
        case 4:
            func_02054080((M2C_UNK *) ((s8 *) &data_02101b78 + (arg0 << 5)),
                          (s32) (u8) * (u16 *) ((s8 *) &data_02101b86 + (arg0 << 5)), (s16) M2C_FIELD(temp_r3, s16 *, 2) >> 8);
            return;
    }
}
