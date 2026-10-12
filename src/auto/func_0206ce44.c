#include "m2c.h"

M2C_UNK func_02053f44(void *, M2C_UNK);             /* extern */
M2C_UNK func_020540b4(void *, M2C_UNK, s32);        /* extern */
M2C_UNK func_02067be4(void *, s32, M2C_UNK, u8, s32, s32, s32); /* extern */
M2C_UNK func_02067c30(void *);                      /* extern */
extern M2C_UNK data_02101b78;

void func_0206ce44(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x78) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0x80;
    func_02067be4(arg0 + 0x4C, M2C_FIELD(arg0, s32 *, 0x54), 0, (u8) M2C_FIELD(arg0, s32 *, 0x78), 0, (s32) (u8) M2C_FIELD(arg0, s32 *, 0x7C), 0xFF);
    func_02067c30(arg0 + 0x4C);
    func_02053f44((M2C_UNK *)((s8 *)&data_02101b78 + (M2C_FIELD(arg0, s32 *, 0x54) << 5)), 0x2000);
    func_020540b4((M2C_UNK *)((s8 *)&data_02101b78 + (M2C_FIELD(arg0, s32 *, 0x54) << 5)), 0x3F, ~(1 << M2C_FIELD(arg0, s32 *, 0x58)) & 0x3F);
}
