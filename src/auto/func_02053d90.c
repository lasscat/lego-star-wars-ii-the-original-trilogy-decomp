#include "m2c.h"

M2C_UNK func_02053398(M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_027e02a8;
extern M2C_UNK data_02101b78;

void func_02053d90(void *arg0) {
    s32 bank;
    s32 i;

    bank = M2C_FIELD(arg0, s32 *, 0);
    if (M2C_FIELD(&data_027e02a8, s32 *, 0) & 0x200) {
        M2C_FIELD(arg0, u8 *, 0x1C) = 0xf;
        bank                        = 0;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C) & 1) {
        *(u32 *) (0x4000000 + bank * 0x1000) = M2C_FIELD(arg0, s32 *, 4);
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C) & 2) {
        if (M2C_FIELD(&data_027e02a8, s32 *, 0) & 0x200) {
            if (!((*(u16 *) 0x4000304 & 0x8000) >> 15)) {
                *(u32 *) 0x400006C = M2C_FIELD(&data_02101b78, u16 *, 0x28);
                *(u32 *) 0x400106C = M2C_FIELD(&data_02101b78, u16 *, 0x8);
            } else {
                *(u32 *) 0x400006C = M2C_FIELD(&data_02101b78, u16 *, 0x8);
                *(u32 *) 0x400106C = M2C_FIELD(&data_02101b78, u16 *, 0x28);
            }
        } else {
            *(u32 *) (0x4000000 + bank * 0x1000 + 0x6C) = M2C_FIELD(arg0, u16 *, 8);
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C) & 4) {
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x50) = M2C_FIELD(arg0, u16 *, 0xA);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x54) = M2C_FIELD(arg0, u16 *, 0xC);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x52) = M2C_FIELD(arg0, u16 *, 0xE);
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C) & 8) {
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x48) = M2C_FIELD(arg0, u16 *, 0x18);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x4A) = M2C_FIELD(arg0, u16 *, 0x1A);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x40) = M2C_FIELD(arg0, u16 *, 0x10);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x42) = M2C_FIELD(arg0, u16 *, 0x12);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x44) = M2C_FIELD(arg0, u16 *, 0x14);
        *(u16 *) (0x4000000 + bank * 0x1000 + 0x46) = M2C_FIELD(arg0, u16 *, 0x16);
    }
    M2C_FIELD(arg0, u8 *, 0x1C) = 0;
    for (i = 0; i < 4; i++) {
        func_02053398(M2C_FIELD(arg0, s32 *, 0), i);
    }
}
