#include "m2c.h"

typedef struct {
    s32 v;
} WordArg;

typedef struct Obj {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0x1A8 - 0xC];
    u16 state;
} Obj;

typedef struct Node {
    Obj *obj;
    struct Node *next;
} Node;

typedef struct {
    u8 pad[4];
    s32 mode;
} Ctx;

typedef struct {
    Node *head;
    Node *first;
} List;

extern Ctx *data_02102900;
extern u8 *func_020aaea8(void);
extern s32 func_0200aef8(void *, void *, WordArg);
extern void func_0200fc60(void *, WordArg);

void func_0200fb9c(List *arg0) {
    Node *node;
    Obj *obj;
    WordArg radius;
    WordArg scale;
    s32 skip;
    s32 mode;

    mode = data_02102900 != NULL ? data_02102900->mode : 0;
    if (mode != 4) {
        return;
    }
    node = arg0->first;
    if (node == NULL) {
        return;
    }
    do {
        obj = node->obj;
        if ((obj->flags & 0x304001) == 0x104001) {
            skip = 1;
            if ((obj->state & 8) == 0) {
                radius.v = 0x64000;
                if (func_0200aef8((u8 *) obj + 0xB0, func_020aaea8() + 0x28, radius) != 0) {
                    skip = 0;
                }
            }
            if (skip == 0) {
                scale.v = 0x1000;
                func_0200fc60((u8 *) obj + 0xB0, scale);
            }
        }
        node = node->next;
    } while (node != NULL);
}
