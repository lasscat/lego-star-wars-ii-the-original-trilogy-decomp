#include "m2c.h"

typedef struct Slot {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC[8];
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1A;
    u16 f1C;
    u8 pad[2];
} Slot;

typedef union Ctl {
    u16 raw;
    struct {
        u16 en : 1;
        u16 rest : 15;
    } b;
} Ctl;

typedef struct Obj {
    Slot slots[2];
    s32 f40;
    s32 f44;
    s32 f48;
    u8 f4C[8];
    u8 f54[8];
    s32 f5C;
    s32 f60;
    u8 pad64[12];
    s32 f70;
    u8 pad74[0x80C];
    Ctl f880;
    u8 pad882[2];
    u16 f884;
    u16 f886;
    u16 f888;
    u16 f88A;
} Obj;

void func_020534e0(void *);
void func_02067bc0(void *);

Obj *func_0206b74c(Obj *arg0) {
    Slot *s;
    u32 i;

    s = arg0->slots;
    do {
        s->f4 = 0;
        s->f8 = 0;
        func_020534e0(s->fC);
        s++;
    } while (s < arg0->slots + 2);
    arg0->f40 = 0;
    arg0->f44 = 0;
    arg0->f48 = 0;
    func_02067bc0(arg0->f4C);
    func_020534e0(arg0->f54);
    arg0->f5C       = 2;
    arg0->f60       = -1;
    arg0->f70       = 0xA0;
    arg0->f884      = 6;
    arg0->f888      = 0;
    arg0->f88A      = 0;
    arg0->f880.raw  = 0;
    arg0->f880.b.en = 1;
    for (i = 0; i < 2; i++) {
        arg0->slots[i].f0  = 0;
        arg0->slots[i].f14 = 0;
        arg0->slots[i].f16 = 0;
        arg0->slots[i].f18 = 0;
        arg0->slots[i].f1C = 0;
        arg0->slots[i].f1A = arg0->slots[i].f1C;
    }
    return arg0;
}
