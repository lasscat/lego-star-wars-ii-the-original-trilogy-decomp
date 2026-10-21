#include "m2c.h"

extern u8 data_020f716c[];
extern void func_02055e98(s32, s32, s32);

typedef struct {
    u8 *bytes;
    u32 acc;
} func_02067a98_struct;

void func_02067a98(func_02067a98_struct *arg0, s32 arg1) {
    u8 *bytes = arg0->bytes;
    u32 count = bytes[0];
    u32 acc   = arg0->acc;
    u32 i;
    u8 *p = bytes + 1;

    for (i = 0; i < count; i++) {
        u8 c = *p++;
        func_02055e98(c, arg1, acc);
        acc += data_020f716c[c];
    }
}
