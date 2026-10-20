#include "m2c.h"

typedef struct Node {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 next;
    s32 f14;
    s8 pad18;
    u8 count;
    u16 flags[1];
} Node;

void func_020c3a8c(u32 *bits, Node *node) {
    s32 base;
    s32 i;
    base = 0;
    while (node != NULL) {
        for (i = base; i < node->count; i++) {
            if (node->flags[i] & 0x100) {
                bits[i >> 5] |= 1 << (i & 31);
            }
        }
        node = node->next;
    }
}
