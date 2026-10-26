#include "m2c.h"

typedef struct Part {
    s32 pad0[2];
    u32 flags;
    u8 pad1[0xC];
    u8 mode_a;
    u8 mode_b;
} Part;

typedef struct Pair {
    u8 pad[0x20];
    Part *left;
    Part *right;
} Pair;

typedef struct Menu {
    s32 pad0[2];
    void *obj8;
    void *objC;
    s32 *obj10;
    Pair *pair;
    u8 pad1[0xF];
    u8 state;
    u8 pad2[0x10];
    Part *extra;
} Menu;

void func_0205365c(s32 *, s32);
void func_0205ea38(s32, s32);
void func_0206574c(void *, s32, s32);
M2C_UNK *func_02066708(s32);
void func_02065be8(void *, s32, s32, s32, M2C_UNK *, s32);
s32 func_02085594(s32 *);
s32 func_0208559c(void *);
void func_0207ed20(void *, s32, s32);
extern s32 data_02104d94[];

enum {
    PART_FLAG_ENABLE     = 0x1,
    PART_FLAG_HIDE_EXTRA = 0x2,
    PART_FLAG_LOCK       = 0x8,
    PART_MODE            = 3,
    MENU_STATE_READY     = 0xF,
};

/* Menu state setup: enables the two list entries (items 8 and 9), then sets up the
   0x8c,0x80 widget and the span from the data_02104d94 range. Names guessed from callers. */
void func_0207e460(Menu *menu) {
    s32 first;
    s32 last;
    Part *l;
    Part *r;
    if (menu->extra != NULL) {
        menu->extra->flags |= PART_FLAG_HIDE_EXTRA;
    }
    func_0205365c(menu->obj10, 0);
    func_0205ea38((s32) &menu->pair, 0);
    menu->pair->left->flags |= PART_FLAG_ENABLE;
    menu->pair->right->flags |= PART_FLAG_ENABLE;
    l         = menu->pair->left;
    l->mode_b = l->mode_a = PART_MODE;
    r                     = menu->pair->right;
    r->mode_b = r->mode_a = PART_MODE;
    menu->pair->left->flags |= PART_FLAG_LOCK;
    menu->pair->right->flags |= PART_FLAG_LOCK;
    func_0206574c(menu->objC, 9, -2);
    func_02065be8(menu->objC, 0x8c, 0x80, 0x3c, func_02066708(0x156), 1);
    func_0206574c(menu->obj8, 6, -2);
    first = func_0208559c(data_02104d94);
    last  = func_02085594(data_02104d94);
    func_0207ed20(menu, last - first, last);
    menu->state = MENU_STATE_READY;
}
