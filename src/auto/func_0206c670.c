#include "m2c.h"

u16 func_0206cf14(void *, s32);
s32 func_0206cf9c(void *, s32);
void func_020536a8(void *, s32);
void func_020536ec(M2C_UNK, void *);
void func_020675d8(void *, s32);
void func_0206b934(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_0206c8e8(void *);
void func_0206ced8(void *);
void func_0206d00c(s32, s32);
extern M2C_UNK data_0210930c;
extern s32 data_027e02a8;

typedef enum Index {
    INDEX_0,
    INDEX_1
} Index;

typedef struct Obj {
    void **vtbl;
} Obj;

typedef struct Ent {
    Obj *obj;
    u8 pad[0x14];
    u16 v18;
    u16 v1a[2];
    u8 pad2[0x2];
} Ent;

typedef struct Flags {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 4;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 b11 : 5;
} Flags;

typedef struct Ctx {
    Ent ent[2];
    u8 pad40[0x14];
    s32 idx;
    u8 pad58[8];
    s32 state;
    u8 pad64[0x81C];
    Flags flags;
    u16 cnt;
    u16 mode;
    u16 sel;
    u16 pad888[2];
    u16 v88c;
    u16 v88e;
    u16 v890;
} Ctx;

void func_0206c670(Ctx *c) {
    switch (c->state) {
        case 3:
            if (!c->flags.b4) {
                c->flags.b4 = func_0206cf14(c, 6);
                return;
            }
            if (c->mode < 3) {
                func_0206c8e8(c);
                return;
            }
            if (c->mode == 5) {
                return;
            }
            c->cnt -= 1;
            if (c->cnt == 0) {
                c->state = 4;
            }
            return;
        case 4:
            if (func_0206cf9c(c, 6) == 0) {
                return;
            }
            c->state = 5;
            func_020536a8(&c->idx, 0);
            func_020536ec(&c->idx, &c->pad40[4]);
            func_0206ced8(c);
            return;
        case 7:
            if (c->ent[c->idx].v18 != 0) {
                func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), u8 **, 4) + 0x28,
                              c->ent[c->idx].v18);
            }
            if (c->mode <= 2) {
                if (c->ent[c->idx].v1a[c->sel] != 0) {
                    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), u8 **, 4) +
                                      0x28,
                                  c->ent[c->idx].v1a[c->sel]);
                }
            }
        case 6: {
            Obj *o;
            func_020536a8(&c->idx, c->flags.b3 != 0 ? 1 : 0);
            o = c->ent[c->idx].obj;
            if (o != 0) {
                s32 which = -1;
                if (c->mode < 3) {
                    which = c->sel;
                }
                ((void (*)(Obj *, s32, s32)) o->vtbl[0])(o, 0, which);
            }
            if (c->mode != 4 && !c->flags.b9) {
                func_0206d00c((s32) c, 0);
            }
            c->state = 0;
            return;
        }
        case 1:
            if ((data_027e02a8 & 0x30) != 0) {
                return;
            }
            if ((data_027e02a8 & 0x3) != 0) {
                return;
            }
            {
            /* Entry slot 0/1. func_0206b934 indexes ent[] with it and saves it in
                 * flags.b10 when it defers to state 1. The enum-typed if/else keeps the
                 * moveq #0 / movne #1 order. */
                Index index;
                if (!c->flags.b10) {
                    index = INDEX_0;
                } else {
                    index = INDEX_1;
                }
                func_0206b934(c, index, c->v88c, c->v88e, c->mode, c->v890);
            }
            return;
        case -1:
        case 0:
        case 2:
        case 5:
            return;
    }
}
