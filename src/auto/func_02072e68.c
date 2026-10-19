#include "m2c.h"
s32 func_0201abbc();
M2C_UNK func_0201b254();
M2C_UNK clearDataAndInstructionCache();
M2C_UNK func_0201c1e4();
s32 func_0205e80c();
typedef struct {
    s16 x;
    s16 y;
} P;
extern u32 data_02104d34[];
extern P data_020edff4[];
extern u32 data_020edfee;

void func_02072e68(u32 arg0) {
    s32 var_r9 = 0;
    u32 var_r0;
    do {
        if (data_02104d34[var_r9] == 0) {
            var_r0 = (u32) func_0205e80c(0x80, 0, 4);
            if (var_r0 != 0) {
                var_r0 = (u32) func_0201abbc(var_r0, arg0);
            }
            data_02104d34[var_r9] = var_r0;
            clearDataAndInstructionCache(data_02104d34[var_r9], &data_020edfee);
            func_0201b254(data_02104d34[var_r9], 0);
            func_0201c1e4(data_02104d34[var_r9], data_020edff4[var_r9].x, data_020edff4[var_r9].y);
        }
        var_r9 += 1;
    } while (var_r9 < 3);
}
