/* Reconstructed from USA ARM9 at 0x0201b48c (392 bytes).
 *
 * arg0 is a game object; the fields used here are a u32 flag word at +0x8,
 * a u32 at +0x10, a u16 at +0x40, a u16 at +0x42, a u8 at +0x45 and a u8
 * index at +0x46.  data_02101b1c holds 12-byte blocks, one per player slot.
 */
#include "m2c.h"

void func_02064cac(M2C_UNK, u32, s32, M2C_UNK);   /* extern */
extern s32 data_027e02a4;
extern s32 data_027e02a8;
extern u8 *data_02101b1c[];

void func_0201b48c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x45) & 3) {
        if (M2C_FIELD(arg0, u16 *, 0x42) == 0xffff) {
            return;
        }
        {
            s16 idx = M2C_FIELD(arg0, u8 *, 0x46);
            *(u8 *) (data_02101b1c[data_027e02a4] + 0xa + idx * 12) =
                *(u8 *) (data_02101b1c[data_027e02a4] + 0xa + idx * 12) - 1;
            if (*(u8 *) (data_02101b1c[data_027e02a4] + 0xa + idx * 12) == 0) {
                s32 flag;
                if (data_027e02a8 & 0x200) {
                    flag = 0;
                } else if (M2C_FIELD(arg0, u32 *, 8) & 0x80000000) {
                    flag = 0;
                } else {
                    flag = 1;
                }
                func_02064cac(M2C_FIELD(arg0, u16 *, 0x42), M2C_FIELD(arg0, u16 *, 0x40),
                              (u8) ((M2C_FIELD(arg0, u32 *, 0x10) << 18) >> 31), flag);
                *(u16 *) (data_02101b1c[data_027e02a4] + idx * 12 + 8)  = 0xffff;
                *(u32 *) (data_02101b1c[data_027e02a4] + idx * 12)      = 0;
                *(u16 *) (data_02101b1c[data_027e02a4] + idx * 12 + 4)  = 0xffff;
                *(u16 *) (data_02101b1c[data_027e02a4] + idx * 12 + 6)  = 0xffff;
                *(u8 *) (data_02101b1c[data_027e02a4] + idx * 12 + 0xb) = 0;
            }
        }
        M2C_FIELD(arg0, u16 *, 0x42) = 0xffff;
        M2C_FIELD(arg0, u16 *, 0x40) = 0;
    } else {
        if (M2C_FIELD(arg0, u16 *, 0x42) == 0xffff) {
            return;
        }
        {
            s32 flag;
            if (data_027e02a8 & 0x200) {
                flag = 0;
            } else if (M2C_FIELD(arg0, u32 *, 8) & 0x80000000) {
                flag = 0;
            } else {
                flag = 1;
            }
            func_02064cac(M2C_FIELD(arg0, u16 *, 0x42), M2C_FIELD(arg0, u16 *, 0x40),
                          (u8) ((M2C_FIELD(arg0, u32 *, 0x10) << 18) >> 31), flag);
        }
        M2C_FIELD(arg0, u16 *, 0x42) = 0xffff;
        M2C_FIELD(arg0, u16 *, 0x40) = 0;
    }
}
