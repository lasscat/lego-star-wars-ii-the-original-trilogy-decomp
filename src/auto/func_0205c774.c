#include "m2c.h"

/* One byte struct passed by value to func_020084b0. */
typedef struct {
    u8 v;
} Byte;

/* Object reached through the controller's item list. */
typedef struct {
    u8 pad[8];
    u8 type;    /* name guessed from callers */
    u8 flag;    /* name guessed from callers */
    u8 fA[4];
    u8 skip;    /* when 0, an adjacent-index update may be skipped */
    u8 kind;    /* 0: gated by controller flag, >= 2: sub-actor update */
} Item;

/* Controller (see func_0205c69c / func_0205c4d4). */
typedef struct {
    Item *item[7];
    u8 unk_1c[0xc];
    u16 unk_28;
    u16 count;
    u16 current;
    u8 num;
    u8 flag;
} Controller;

typedef struct {
    u8 unk_00[0x44];
    u8 flag_a;
    u8 flag_b;
} Input;

/* Integer absolute value. */
static inline s32 iabs(s32 v) {
    if (v < 0) {
        v = -v;
    }
    return v;
}

enum {
    ACTOR_SUB_OFFSET  = 0x2c,
    ACTOR_ITEM_OFFSET = 0x10,
};

extern Item *func_01ffa478(Item *, s32);
extern void func_0205ca98(void *, Item *, Input *);
extern void func_0200af88(u8 *, u8);
extern void func_020084b0(void *, Byte, u8, Item *, Input *);

/* Updates every item of the controller for frame index `index` (clamped to
   the controller's count). Returns 1 if a kind-0 item was updated, else 0. */
s32 func_0205c774(Controller *self, u8 *actor, Input *input, s32 index) {
    s32 result;
    s32 i;
    Item *obj;
    u8 skip;
    s32 kind;

    if (index >= self->count) {
        index = self->count - 1;
    }
    if (self->current == (u16) index && (input->flag_a | input->flag_b) == 0) {
        return 0;
    }
    result = 0;
    for (i = 0; i < self->num; i++) {
        obj  = func_01ffa478(self->item[i], index);
        skip = obj->skip;
        kind = obj->kind;
        if (skip == 0 && iabs(self->current - (u16) index) == 1 && (input->flag_a | input->flag_b) == 0) {
            continue;
        }
        if (kind == 0) {
            if (self->flag != 0) {
                continue;
            }
            result = 1;
        }
        if (kind >= 2) {
            func_0205ca98(actor + ACTOR_SUB_OFFSET, obj, input);
        } else {
            Byte b;
            u8 type = self->item[i]->type;
            func_0200af88(&b.v, self->item[i]->flag);
            func_020084b0(actor + ACTOR_ITEM_OFFSET, b, type, obj, input);
        }
    }
    return result;
}
