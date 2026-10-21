#include "m2c.h"

typedef struct {
    u16 a;
    u16 b;
} Ent;

s32 func_020061bc(s32 a0, u16 *out, s32 a2, s32 a3) {
    s32 i;
    u16 key;
    Ent *tbl;
    s32 res;
    key = *(u16 *) (a3 + 2);
    i   = 0;
    tbl = *(Ent **) (a2 + 0x20);
    res = 0;
    for (;;) {
        if (tbl[i].a == key) {
            res    = 1;
            out[0] = *(u16 *) a3;
            out[1] = *(u16 *) (*(u32 *) (a2 + 0x20) + i * 4 + 2);
            break;
        }
        i++;
        if (tbl[i].a == 0xFFFF) {
            break;
        }
    }
    return res;
}
