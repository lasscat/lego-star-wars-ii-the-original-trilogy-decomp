#include "m2c.h"

typedef struct {
    u16 f00;
    u8 f02;
    u8 f03;
} Elem;

typedef struct {
    void *f00;
    void *f04;
} Ctx;

typedef struct {
    u8 pad000[0x38C];
    Ctx *f38C;
    u8 pad390[0xEC];
    u8 f47C;
    u8 f47D;
    Elem f47E[8];
} Sub;

extern void func_020675d8(void *, u8);
extern void func_0206763c(void *, u8);

void func_0208fa54(Sub *s) {
    u32 i;

    for (i = 0; i < s->f47C; i++) {
        if (s->f47E[i].f00 == 0) {
            u8 *cnt = &s->f47C;
            func_020675d8(s->f38C->f04 + 0x28, s->f47E[i].f03);
            func_0206763c(s->f38C->f04 + 0x28, s->f47E[i].f02);
            if (i < s->f47C - 1) {
                s->f47E[i].f00 = s->f47E[s->f47C - 1].f00;
                s->f47E[i].f02 = s->f47E[s->f47C - 1].f02;
                s->f47E[i].f03 = s->f47E[s->f47C - 1].f03;
            }
            *cnt = *cnt - 1;
        } else {
            s->f47E[i].f00 = s->f47E[i].f00 - 1;
        }
    }
}
