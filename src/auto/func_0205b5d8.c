#include "m2c.h"

void func_0205b5d8(s32 *a0) {
    s32 node  = *a0;
    s32 child = *(s32 *) (node + 4);
    s32 parent;

    if (child != 0) {
        s32 next = *(s32 *) child;
        while (next != 0) {
            child = next;
            next  = *(s32 *) next;
        }
        *a0 = child;
        return;
    }
    parent = *(s32 *) (node + 8) & ~1;
    while (node != *(s32 *) parent) {
        *a0    = parent;
        node   = *a0;
        parent = *(s32 *) (node + 8) & ~1;
    }
    *a0 = parent;
}
