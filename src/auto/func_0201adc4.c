#include "m2c.h"

typedef struct {
    s32 v;
} S32;

M2C_UNK func_02060cd0(u32 *, M2C_UNK, M2C_UNK);        /* extern */
void clearDataAndInstructionCache(u32 *, M2C_UNK);      /* extern */
void func_0201b254(u32 *, s32);                        /* extern */
extern s32 data_027e02a8;

void func_0201adc4(void *arg0, M2C_UNK arg1, M2C_UNK arg2, S32 arg3, u32 arg4, u8 arg5, ...) {
    s32 var_r2;
    u32 *f0;

    f0 = M2C_FIELD(arg0, volatile u32 *, 0);
    if (data_027e02a8 & 0x200) {
        var_r2 = 0;
    } else if (M2C_FIELD(f0, volatile s32 *, 8) & 0x80000000) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    func_02060cd0(M2C_FIELD(arg0, volatile u32 *, 0), arg1, var_r2);
    clearDataAndInstructionCache(M2C_FIELD(arg0, volatile u32 *, 0), arg2);
    M2C_FIELD(M2C_FIELD(arg0, volatile u32 *, 0), s32 *, 0x4c) = arg3.v;
    M2C_FIELD(M2C_FIELD(arg0, volatile u32 *, 0), s32 *, 0x50) = arg4;
    func_0201b254(M2C_FIELD(arg0, volatile u32 *, 0), arg5);
}
