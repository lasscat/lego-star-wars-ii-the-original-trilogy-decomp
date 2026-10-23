#include "m2c.h"
s32 func_02062a7c(s32, s32);
void *func_0205e80c(s32, s32, s32);
void func_020327ec(void *, s32, u16, s32);
void func_0202dc70(s32 arg0, s32 arg1, s32 arg2) {
    u16 var_r4;
    s32 var_r3;
    void *ptr;

    switch (arg1) {
        case 1:
            var_r4 = (u16) func_02062a7c(0xC8, 0x12C);
            break;
        case 2:
            var_r4 = (u16) func_02062a7c(0xA, 0x3C);
            break;
    }

    ptr = func_0205e80c(0x20, 1, 4);
    if (ptr == 0) {
        return;
    }
    if (arg1 != 1) {
        arg2 = 0;
    }
    var_r3 = (arg2 != 0) ? 1 : 0;
    func_020327ec(ptr, arg0, var_r4, var_r3);
}
