#include "m2c.h"

extern M2C_UNK data_021019c0[];

u16 func_02007f58(void);

s32 func_020081f0(s32 *obj) {
    s32 i;
    *(s32 *)((u8 *)obj + 0x18) = -1;
    for (i = 0; i < 2; i++) {
        obj[4 + i] = 0;
        obj[i] = 0;
    }
    if (*(u16 *)data_021019c0 == 0) {
        *(u16 *)data_021019c0 = func_02007f58();
    }
    return obj;
}
