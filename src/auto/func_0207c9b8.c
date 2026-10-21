#include "m2c.h"

extern void func_0205e8d0(M2C_UNK);
extern void func_0200fa74(M2C_UNK);
extern void func_0200171c(s32);
extern void func_020ac278(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 data_027e02a4;
extern M2C_UNK data_027e0874;
extern M2C_UNK data_021019f4;

void func_0207c9b8(M2C_UNK arg0) {
    func_0205e8d0(arg0 + 0xa4);
    func_0200fa74((s32 *) ((s8 *) &data_021019f4 + data_027e02a4 * 0x38));
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_0200fa74((s32 *) ((s8 *) &data_021019f4 + data_027e02a4 * 0x38));
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_0200171c(0);
    func_020ac278(&data_027e0874, 4, 0);
}
