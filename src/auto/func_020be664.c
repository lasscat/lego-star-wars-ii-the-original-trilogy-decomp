#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
} Pair;

typedef struct {
    s32 pad[2];
    s32 v0;
    s32 v1;
    s32 flag;
} Out;

typedef struct {
    s32 pad;
    s32 a0;
    s32 a1;
    s32 b0;
    s32 b1;
} In;

In *func_020be664(Out *o, In *in) {
    Pair a;
    Pair b;
    Pair c;
    Pair d;

    a.y = in->a0;
    a.x = in->a1;
    b.y = in->b0;
    b.x = in->b1;
    if (b.y != 0 || b.x != 0) {
        c       = b;
        o->v0   = c.y;
        o->v1   = c.x;
        o->flag = 1;
    } else {
        d       = a;
        o->v0   = d.y;
        o->v1   = d.x;
        o->flag = 0;
    }
    return in + 1;
}
