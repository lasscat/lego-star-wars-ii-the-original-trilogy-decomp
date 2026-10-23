#include "m2c.h"

void func_0206763c(void *, s32);
void func_020675d8(void *, s32);

typedef struct {
    u32 count;
    u8 pad4;
    u8 flag5;
    u8 flag6;
    u8 flag7;
} Entry;

typedef struct {
    u8 pad[0x28];
    u32 val;
} Ctl;

typedef struct {
    u32 pad0;
    Ctl *ctl;
} Holder;

typedef struct {
    u8 pad[0x38c];
    Holder *holder;
    u8 pad2[0x3e8 - 0x38c - 4];
    Entry entry[1];
} Obj;

void func_020907d4(Obj *self, s32 idx) {
    Entry *e = &self->entry[idx];
    if (++e->count == 0) {
        if (e->flag6 != 0) {
            func_0206763c(&self->holder->ctl->val, e->flag6);
        }
        if (e->flag7 != 0) {
            func_020675d8(&self->holder->ctl->val, e->flag7);
        }
    }
    if (e->flag5 != 0) {
        func_020675d8(&self->holder->ctl->val, e->flag5);
    }
}
