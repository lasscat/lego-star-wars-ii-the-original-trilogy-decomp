#include "m2c.h"

extern M2C_UNK data_020fe1b0[];

void func_0205e84c(s32);

s32 func_0203c0ac(s32 *obj) {
    s32 *child;
    s32 *sub;
    *(s32 *) obj                                        = (s32) data_020fe1b0;
    *(s32 *) ((u8 *) *(s32 *) ((u8 *) obj + 4) + 0x690) = 0;
    child                                               = *(s32 *) ((u8 *) obj + 0x10);
    if (child != 0) {
        sub = child[1];
        if (sub != 0) {
            if (sub != 0) {
                *(u8 *) ((u8 *) sub + 0x5d6) = 0;
                sub                          = child[1];
                sub[2] |= 0x20;
            }
            child[1] = 0;
        }
        func_0205e84c(child);
    }
    return obj;
}
