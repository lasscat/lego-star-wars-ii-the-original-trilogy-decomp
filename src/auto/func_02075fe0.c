#include "m2c.h"

typedef struct Holder {
    s32 pad[3];
    s32 *items[4];
} Holder;

void func_02075fe0(Holder *base) {
    s32 i = 0;
    do {
        s32 *p = base->items[i];
        ++i;
        p[2] &= ~1;
    } while (i < 4);
}
