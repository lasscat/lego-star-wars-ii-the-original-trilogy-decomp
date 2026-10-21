#include "m2c.h"

typedef struct {
    u8 pad0[0x270];
    s16 f270;
    s16 f272;
    u16 pad2;
    u16 f276;
    s8 f278;
} G;

void func_020a2064(void *arg0, u16 arg1, ...) {
    G *p = (G *) arg0;
    volatile u16 v0;
    volatile u16 v1;
    volatile u16 v2;
    volatile u16 v3;

    p->f270 = *(u16 *) &arg1;
    p->f278 = 0;
    if (p->f270 > p->f272) {
        u16 t;
        p->f278 = 1;
        v0      = (u16) (p->f272 + ((p->f270 - p->f272) / 2));
        t       = v0;
        v2      = t;
        p->f276 = t;
    } else if (p->f270 < p->f272) {
        u16 u;
        p->f278 = -1;
        v1      = (u16) (p->f270 + ((p->f272 - p->f270) / 2));
        u       = v1;
        v3      = u;
        p->f276 = u;
    }
}
