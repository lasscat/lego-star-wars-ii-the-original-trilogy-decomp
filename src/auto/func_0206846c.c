#include "m2c.h"

typedef struct Item {
    u8 pad0[0x14];
    u32 lo : 12;
    u32 nib : 4;
    u32 hi : 16;
    u8 pad1[0x45 - 0x18];
    u8 flags;
    u8 b46;
    u8 pad2[5];
    s32 f4c;
    s32 f50;
} Item;

typedef struct List {
    u8 pad[8];
    Item *items[1];
} List;

typedef struct Obj {
    u8 pad0[0xc];
    List *list;
    u8 pad1[0x35 - 0x10];
    u8 enabled;
} Obj;

enum {
    ITEM_FLAG_HIDDEN = 0x1,    /* guessed from use: set on all 8 items */
    NUM_ITEMS_ALL    = 8,
    NUM_ITEMS_ROW    = 4,
    NIB_OFF          = 14,              /* 4-bit field value when table entry is zero */
    NIB_ON           = 15,               /* 4-bit field value when table entry is nonzero */
    ROW_START_X      = 0x28000,     /* fixed-point (.16) start position */
    ROW_STEP_X       = 0x30000,      /* fixed-point (.16) spacing between items */
    ROW_Y            = 0x48000,           /* fixed-point (.16) row position */
    TABLE_WORD_OFS   = 0x4c / 4  /* word index of the per-item array in data_0210930c */
};

void func_02055ba4(s32, s32, M2C_UNK, M2C_UNK, s32);
void func_0205e938(void *, s32, u32, M2C_UNK);
void func_0205ea84(void *, s32);
void func_020691a0(s32);
extern M2C_UNK data_020ede22;
extern s32 data_0210930c[];

/* Sets up the screen's list of 8 items, then (if enabled) lays out the first 4 in a row
 * and picks each one's 4-bit state from a per-item table. */
void func_0206846c(Obj *arg0) {
    u32 i;
    u32 j;
    s32 pos;

    func_02055ba4(0xf52, 0x20, 0xd0, 0x10, 1);
    func_02055ba4(0xf52, 0x40, 0xe0, 0x10, 1);
    func_0205e938(&arg0->list, (s32) &data_020ede22, 0xa, 1);
    for (i = 0; i < NUM_ITEMS_ALL; i++) {
        arg0->list->items[i]->flags |= ITEM_FLAG_HIDDEN;
        arg0->list->items[i]->b46 = 0;
    }
    func_0205ea84(&arg0->list, 1);
    if (arg0->enabled == 0) {
        return;
    }
    func_020691a0((s32) arg0);
    pos = ROW_START_X;
    for (j = 0; j < NUM_ITEMS_ROW; j++) {
        Item *it;
        s32 n   = (data_0210930c[TABLE_WORD_OFS + j] == 0) ? NIB_OFF : NIB_ON;
        it      = arg0->list->items[j];
        it->nib = n;
        it      = arg0->list->items[j];
        it->f4c = pos;
        it->f50 = ROW_Y;
        pos += ROW_STEP_X;
    }
}
