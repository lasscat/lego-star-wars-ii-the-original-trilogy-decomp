#include "m2c.h"

/* One byte struct passed by value to func_02008614. */
typedef struct {
    u8 v;
} Byte;

/* Object reached through the control block's item list. */
typedef struct {
    u8 pad[8];
    u8 f8;
    u8 f9;
    u8 fA[5];
    u8 ff;
} Item;

/* 0x30 byte control block (see func_0205c324 / func_0205c5d4). */
typedef struct {
    Item *item[7];
    void *f1c;
    void *f20;
    void *f24;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u8 f2e;
    u8 f2f;
} Ctrl;

extern void func_0205c924(Ctrl *, void *);
extern void func_0205ccd4(void **);
extern Item *func_01ffa478(Item *, s32);
extern void func_0200af88(u8 *, u8);
extern void func_02008614(void *, u8, Byte, Item *, void *);
extern void func_0205c9e4(void *, Item *, void *);

void func_0205c4d4(Ctrl *a0, void *a1, void *a2, s32 a3, s32 a4) {
    Item *obj;
    s32 idx;
    s32 flag;
    s32 i;

    if (a0->f28 == 0xffff) {
        return;
    }
    idx = a3;
    if (idx >= (s32) a0->f2a) {
        idx = (s32) a0->f2a - 1;
    }
    func_0205c924(a0, a1);
    func_0205ccd4((void **) ((u8 *) a1 + 0x2c));

    for (i = 0; i < (s32) a0->f2e; i++) {
        obj  = func_01ffa478(a0->item[i], idx);
        flag = obj->ff;
        if (a4 == 0 && flag == 0 && a0->f2f != 0) {
            continue;
        }
        if (flag >= 2) {
            func_0205c9e4((u8 *) a1 + 0x2c, obj, a2);
        } else {
            Byte b;
            func_0200af88(&b.v, a0->item[i]->f9);
            func_02008614((u8 *) a1 + 0x10, a0->item[i]->f8, b, obj, a2);
        }
    }
}
