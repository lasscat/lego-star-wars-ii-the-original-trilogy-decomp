#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

void func_01ffad38(u32 *, UnkVal, void *);
void func_0200c31c(s32, s32);
void func_02010384(void *, UnkVal);

void func_0200c28c(void *arg0, UnkVal arg1, ...) {
    u32 i;
    u8 *elem;
    u8 *sub;
    s8 idx;
    u32 *node;

    for (i = 0; i < 0xC; i++) {
        elem = (u8 *) arg0 + i * 0x28;
        sub  = elem + 0x100;
        idx  = *(s8 *) (sub + 0xe1);
        node = *(u32 **) (elem + 0x1d0);
        if (node != NULL && idx != -1) {
            u8 *other = (u8 *) arg0 + idx * 0x38;
            if (other[0x3cc] != 0 && elem[0x1df] != 0) {
                func_01ffad38(node, arg1, arg0);
                func_0200c31c((s32) arg0, i);
            }
        }
    }
    func_02010384(arg0, arg1);
}
