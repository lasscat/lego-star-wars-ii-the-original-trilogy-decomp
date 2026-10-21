#include "m2c.h"

/* func_01ffa478(base, index) returns base->items[index], where the item size
   is taken from a table indexed by the list type (byte at offset 8). */
extern void *func_01ffa478(void *, s32);

/* The list object: word 0 is the item array, byte 8 the type, byte 9 a flag. */
typedef struct {
    void *items;
    u8 unk_04[4];
    u8 type;
    u8 flag;
} List0205c628;

/* One item of a list. The first three words are the position vector, byte
   0x0f is the item kind that is looked at here. */
typedef struct {
    s32 pos[3];
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e;
    u8 kind;
} Item0205c628;

/* The owner object (see func_0205c5d4 / func_0205c69c / func_0205c4d4). */
typedef struct {
    List0205c628 *lists[7];
    s32 pos[3];
    u16 unk_28;
    u16 unk_2a;
    u16 unk_2c;
    u8 count;
    u8 flag;
} Unk0205c628;

void func_0205c628(Unk0205c628 *self, s32 a1) {
    s32 i;
    s32 index = 0;
    Item0205c628 *item;

    if (a1 == 0) {
        return;
    }
    for (i = 0; i < 7; i++) {
        if (self->lists[i] == NULL) {
            continue;
        }
        item = func_01ffa478(self->lists[i], index);
        if (item->kind != 0) {
            continue;
        }
        /* The item may already be the position buffer of this object. */
        if ((void *) &self->pos != (void *) item) {
            self->pos[0] = item->pos[0];
            self->pos[1] = item->pos[1];
            self->pos[2] = item->pos[2];
        }
        self->flag = a1;
        return;
    }
}
