#include "m2c.h"

typedef struct {
    u32 f00;
    u32 f04;
    s32 f08;
    u8 f0C;
    u8 f0D;
    u8 f0E;
    u8 f0F;
} Elem;

typedef struct {
    void *f00;
    void *f04;
} Ctx;

typedef struct {
    u8 pad000[0x38C];
    Ctx *f38C;
    u8 pad390[0x98];
    Elem f428[5];
} Sub;

extern u32 OS_GetTick(void);
extern u64 _ll_udiv(u64 n, u64 d);
extern void func_020675d8(void *, u8);
extern void func_0206763c(void *, u8);

void func_02090918(Sub *s) {
    u32 i;

    for (i = 0; i < 5; i++) {
        Elem *e = &s->f428[i];
        if (e->f0D != 0) {
            u32 tick = OS_GetTick();
            e->f08   = e->f08 - (s32) (tick - e->f00);
            e->f04   = (u32) _ll_udiv((u64) ((s64) e->f08 << 6), 0x1FF6210);
            e->f00   = tick;
            if (e->f08 <= 0) {
                if (e->f0F != 0) {
                    func_0206763c(s->f38C->f04 + 0x28, e->f0F);
                }
                if (e->f0E != 0) {
                    func_020675d8(s->f38C->f04 + 0x28, e->f0E);
                }
                e->f0D = 0;
                e->f0C = 0;
            }
        }
    }
}
