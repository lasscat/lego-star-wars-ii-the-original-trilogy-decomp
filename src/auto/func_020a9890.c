#include "m2c.h"

/* The object holds a nested structure at +0x100 whose u16 member is at +0x1a8;
   the s32 member that is reset to -1 is at +0x1ac. */
typedef struct {
    u8 pad[0xa8];
    u16 idx;
} Inner020a9890;

typedef struct {
    u8 pad[0x100];
    Inner020a9890 in;
    u8 pad2[2];
    s32 flag;
} Obj020a9890;

void func_020a9890(Obj020a9890 *o, u16 v, ...) {
    volatile u16 tmp[2];
    tmp[0] = o->in.idx;
    if (*(u16 *) &v == o->in.idx) {
        return;
    }
    tmp[1]    = *(u16 *) &v;
    o->in.idx = tmp[1];
    o->flag   = -1;
}
