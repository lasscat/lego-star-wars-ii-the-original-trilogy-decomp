#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s32 a;
    s32 b;
} Pair;

typedef struct {
    void *vtbl;
    s8 pad4[4];
    Pair pairs[2];
    s32 f18;
    s32 f1c;
    u16 pad20;
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
} Obj;

extern void *func_02062694(void *self, s32 a, s8 b);
extern void func_020534e0(Pair *p);
extern void func_020534f4(Pair *p, s32 a, s32 b, HalfWord h);
extern void func_020536a8(Pair *p, s32 flag);
extern void *data_020fe8bc;
extern const HalfWord data_020edeb8[];

Obj *func_0206d4d0(Obj *self, s32 arg1, u16 arg2, s32 arg3, s32 arg4) {
    Pair *p;
    func_02062694(self, 0, 0);
    self->vtbl = &data_020fe8bc;
    p          = self->pairs;
    do {
        func_020534e0(p);
        p++;
    } while (p < &self->pairs[2]);
    self->f18 = 0;
    self->f1c = arg1;
    self->f22 = 0;
    self->f24 = arg2;
    self->f26 = 0;
    self->f28 = 0;
    self->f2a = 1;
    func_020534f4(&self->pairs[0], self->f1c, arg3, data_020edeb8[1]);
    func_020534f4(&self->pairs[1], self->f1c, arg4, data_020edeb8[0]);
    func_020536a8(&self->pairs[0], 0);
    func_020536a8(&self->pairs[1], 0);
    return self;
}
