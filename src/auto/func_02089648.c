#include "m2c.h"

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s8 f8;
    s8 f9;
} Item;

typedef struct {
    u8 pad0[0x28C4];
    Item items[7];
    s8 f290A;
} S;

s8 func_02093fd0(M2C_UNK);                          /* extern */

void func_02089648(S *arg0, M2C_UNK arg1) {
    u8 i;

    if (arg0->f290A == func_02093fd0(arg1)) {
        return;
    }
    i = 0;
    do {
        arg0->items[i].f2 = 0;
        arg0->items[i].f0 = 0;
        arg0->items[i].f8 = -1;
        arg0->items[i].f6 = 0;
        arg0->items[i].f4 = 0;
        arg0->items[i].f9 = 0;
        i += 1;
    } while (i < 7);
    arg0->f290A = func_02093fd0(arg1);
}
