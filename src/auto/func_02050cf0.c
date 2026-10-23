#include "m2c.h"

extern s32 data_027e02a8;
extern M2C_UNK data_02106d90;
extern u8 data_02106fb4[];
extern u8 data_02106fb8[];
extern u8 data_02106fcc[];
extern u8 data_02106fd8[];
extern u8 data_02106ff2[];
extern u8 data_02106ff3[];
extern M2C_UNK data_0210930c;

s32 func_02073034(void);
void func_02001688(s32);
void func_020016c0(void);
M2C_UNK func_02091b88(M2C_UNK *, u8, s16, s32 *, s32);

s32 func_02050cf0(void *arg0) {
    s32 sp4[3];
    u32 *dst;
    u32 *p;
    u8 *st;

    if (data_027e02a8 & 0x40) {
        if (M2C_FIELD(arg0, u8 *, 8) < func_02073034()) {
            st = data_02106ff3;
            if (*(st + M2C_FIELD(arg0, u8 *, 8) * 64) == 0) {
                *(u16 *) (data_02106fd8 + M2C_FIELD(arg0, u8 *, 8) * 64) = M2C_FIELD(arg0, u8 *, 9);
                dst = (u32 *) (data_02106fb4 + M2C_FIELD(arg0, u8 *, 8) * 64);
                if (dst != (u32 *) data_02106fb4) {
                    dst[0] = *(u32 *) data_02106fb4;
                    dst[1] = *(u32 *) ((u8 *) &data_02106d90 + 0x228);
                    dst[2] = *(u32 *) ((u8 *) &data_02106d90 + 0x22c);
                }
                *(u32 *) (data_02106fb8 + M2C_FIELD(arg0, u8 *, 8) * 64) += 0xF000;
                *(u8 *) (data_02106ff2 + M2C_FIELD(arg0, u8 *, 8) * 64)  = 4;
                *(u32 *) (data_02106fcc + M2C_FIELD(arg0, u8 *, 8) * 64) = -1;
            }
            *(st + M2C_FIELD(arg0, u8 *, 8) * 64) = 0;
            func_02001688(0);
            p      = (u32 *) (data_02106fb4 + M2C_FIELD(arg0, u8 *, 8) * 64);
            sp4[0] = p[0];
            sp4[1] = p[1];
            sp4[2] = p[2];
            func_02091b88(&data_0210930c, M2C_FIELD(arg0, u8 *, 8), *(s16 *) (data_02106fd8 + M2C_FIELD(arg0, u8 *, 8) * 64),
                          sp4, 1);
            func_020016c0();
        }
    }
    return 0;
}
