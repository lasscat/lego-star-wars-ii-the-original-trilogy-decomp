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

extern u32 *func_0205ab58(s32);
extern s32 func_01ffa408(u32 **);
extern Item *func_0205e80c(s32, s32, s32);
extern Item *func_0205c0bc(Item *);
extern s32 func_0205c8d4(Ctrl *, u32 **, s32, s32);
extern Item *func_01ffa478(Item *, s32);
extern void func_0205c9e4(void *, Item *, void *);
extern void func_0200af88(u8 *, u8);
extern void func_02008614(void *, u8, Byte, Item *, void *);

s32 func_0205c37c(Ctrl *a0, void *a1, s32 a2, void *a3, s32 a4) {
    u32 *cursor;
    Item *item;
    Item *obj;
    s32 flag;
    s32 i;

    a0->f28 = (u16) a2;
    a0->f2c = (u16) a4;
    if (a2 == 0xffff) {
        return 0;
    }
    cursor = func_0205ab58(a2);
    func_01ffa408(&cursor);
    a0->f2a = (u16) func_01ffa408(&cursor);
    a0->f2e = (u8) func_01ffa408(&cursor);
    func_01ffa408(&cursor);
    if (a4 >= (s32) a0->f2a) {
        a4 = (s32) a0->f2a - 1;
    }
    for (i = 0; i < (s32) a0->f2e; i++) {
        item = func_0205e80c(0xc, 3, 4);
        if (item != 0) {
            item = func_0205c0bc(item);
        }
        a0->item[i] = item;
        func_0205c8d4(a0, &cursor, i, a0->f2a);
        obj  = func_01ffa478(a0->item[i], a4);
        flag = obj->ff;
        if (flag == 0 && a0->f2f != 0) {
            continue;
        }
        if (flag >= 2) {
            func_0205c9e4((u8 *) a1 + 0x2c, obj, a3);
        } else {
            Byte b;
            func_0200af88(&b.v, a0->item[i]->f9);
            func_02008614((u8 *) a1 + 0x10, a0->item[i]->f8, b, obj, a3);
        }
    }
    return 1;
}
