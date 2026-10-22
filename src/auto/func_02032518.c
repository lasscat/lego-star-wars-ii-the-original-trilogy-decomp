#include "m2c.h"

/* A two byte aggregate, passed by value. */
typedef struct {
    u16 v;
} HalfVal;

/* The animated object; only the status word at +0x08 is inspected here. */
typedef struct {
    u8 pad0[8];
    u32 status;
} Entity;

/* The controller object. */
typedef struct {
    u8 pad0[4];
    Entity *ent;    /* +0x04 */
    u32 pad8;
    u8 flag_c;      /* +0x0c */
    u8 flag_d;      /* +0x0d */
    u8 pad_e[2];
    Entity *target; /* +0x10 */
    HalfVal h14;    /* +0x14 */
    u8 flag_16;     /* +0x16 */
} Obj;

extern void func_0201811c(u16 *, Entity *, Entity *, s32);
extern void func_02018210(Entity *, HalfVal, HalfVal);

void func_02032518(Obj *o) {
    /* The halfword scratch values are volatile: the stores and reloads they
     * generate are part of the original code. */
    volatile u16 zero;
    HalfVal res;
    volatile u16 copy;
    u16 tmp;

    if (o->flag_d != 0) {
        return;
    }
    if (o->target != NULL && (o->target->status & 0x802) != 0) {
        o->target = NULL;
        o->flag_c |= 1;
        return;
    }
    {
        int done = 0;
        int flag = 0;
        if (o->flag_16 == 0) {
            zero = 0;
            tmp  = zero;
            copy = tmp;
            flag = (o->h14.v != tmp);
        }
        if (flag && (o->target != NULL)) {
            done = 1;
        }
        if (!done) {
            return;
        }
    }
    func_0201811c(&res.v, o->ent, o->target, 0);
    func_02018210(o->ent, res, o->h14);
}
