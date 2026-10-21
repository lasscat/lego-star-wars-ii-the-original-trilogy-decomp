#include "m2c.h"

extern void func_02008288(s32 arg0, s32 arg1, s32 arg2);

void func_0205c924(u8 *arg0, u32 *arg1) {
    s32 i;
    s32 flag;

    for (i = 0; i < 2; i++) {
        if (i != 0 || arg0[0x2f] == 0) {
            flag = (arg1[8 + i] != 0) ? 1 : 0;
            if (flag != 0) {
                func_02008288((s32) (arg1 + 4), i, 0);
            }
        }
    }
}
