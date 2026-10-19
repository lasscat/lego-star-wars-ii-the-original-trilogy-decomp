#include "m2c.h"

typedef struct UnkIrqCallbackInfo {
    M2C_UNK (*func)(s32);
    s32 enable;
    s32 arg;
} UnkIrqCallbackInfo;

extern UnkIrqCallbackInfo data_021153f0[8];
M2C_UNK func_020ccb04(s32);

void func_020cca90(u32 arg0, M2C_UNK (*arg1)(s32), s32 arg2) {
    u32 mask;

    mask                     = 1 << (arg0 + 3);
    data_021153f0[arg0].func = arg1;
    data_021153f0[arg0].arg  = arg2;
    func_020ccb04(mask);
    data_021153f0[arg0].enable = 1;
}
