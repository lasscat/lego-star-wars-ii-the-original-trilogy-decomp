/* Reconstructed from USA ARM9 at 0x0206b06c (888 bytes). */
#include "engine.h"
#include "m2c.h"

struct S_0206b06c_Data {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    u16 f2a;
    u16 f2c;
};

typedef struct {
    void (*f0)(void *);
    void (*f1)(void *);
    void (*f2)(void *);
} S_0206b06c_Vtbl;

typedef struct {
    S_0206b06c_Vtbl *vtbl;
    u8 pad[4];
    u16 f8;
} S_0206b06c_Obj;

typedef struct {
    u8 pad[8];
    u16 f8;
} S_0206b06c_Flag;

typedef struct {
    u8 pad[0x20];
    u32 f20;
    S_0206b06c_Flag *p24;
} S_0206b06c_Owner;

typedef struct {
    u8 pad0;
    u8 b;
    u16 s;
    u8 pad4[8];
} S_0206b06c_Elem;

typedef struct {
    u8 pad00[0x4];
    S_0206b06c_Owner *p04;
    u8 pad08[0x8];
    void *p10;
    S_0206b06c_Obj *p14;
    u32 f18;
    u8 pad1c[0x4];
    u32 f20;
    u32 f24;
    S_0206b06c_Elem arr[8];
} S_0206b06c_Self;

extern struct S_0206b06c_Data data_021044a4;
extern M2C_UNK data_021027f8;

s32 func_02064a58(void *, void *);
void func_020b8f70(s32, s32);
void func_0205365c(void *, s32);
void func_0206b3e4(void *, s32);
void func_0206b5c4(void *);
s32 func_0205cfe8(void *, void *, s32, u32, s32);
s32 func_0205d0d0(void *, s32, s32);
s32 func_0205d060(void *, s32, s32);
s32 func_0206b628(void *, s32, s32);

void func_0206b06c(S_0206b06c_Self *self) {
    u16 loc[2];

    if (self->p14 != 0) {
        self->p14->vtbl->f2(self->p14);
        if (!(self->p14->f8 & 1)) {
            return;
        }
        if (self->p14 != 0) {
            self->p14->vtbl->f1(self->p14);
        }
        self->p14 = 0;
        func_0205365c(self->p10, 0);
        func_0206b3e4(self, 1);
        return;
    }

    {
        s32 flag = 0;
        u32 i;
        loc[0] = 0;
        loc[1] = 0;
        if (data_021044a4.b2) {
            loc[0] = data_021044a4.f2a;
            loc[1] = data_021044a4.f2c;
        }
        for (i = 0; i < self->f24; i++) {
            if (func_02064a58(&self->arr[i], loc) == 0) {
                continue;
            }
            if ((self->f18 == i && self->arr[i].b != 0) || (s32) self->arr[i].s >= 10) {
                func_0206b5c4(self);
            } else if (self->f18 != i && self->arr[i].b != 0) {
                self->f18 = i;
                func_020b8f70(0xb6, 0);
                func_0206b3e4(self, 0);
                self->f20 = 0;
            }
            flag = 1;
            break;
        }
        if (flag != 0) {
            return;
        }
        if (func_0205cfe8(&data_021027f8, &self->f18, 0, self->f24, 4)) {
            func_020b8f70(0xb6, 0);
            func_0206b3e4(self, 0);
            self->f20 = 0;
            return;
        }
        if (func_0205d0d0(&data_021027f8, 1, 4)) {
            func_0206b5c4(self);
            self->f20 = 0;
            return;
        }
        if (func_0205d0d0(&data_021027f8, 2, 4)) {
            func_020b8f70(0xb5, 0);
            self->p04->p24->f8 |= 1;
            self->p04->f20 |= 4;
            return;
        }
        if (self->f18 <= 1) {
            if (func_0205d0d0(&data_021027f8, 0x330, 4)) {
                s32 a = 1;
                s32 b = 0;
                if (func_0205d0d0(&data_021027f8, 0x10, 4)) {
                    a = b;
                } else if (func_0205d0d0(&data_021027f8, 0x100, 4)) {
                    a = b;
                    b = 1;
                } else if (func_0205d0d0(&data_021027f8, 0x200, 4)) {
                    b = a;
                }
                if (func_0206b628(self, a, b) == 0) {
                    return;
                }
                func_0206b3e4(self, 0);
                return;
            } else if (func_0205d060(&data_021027f8, 0x30, 4)) {
                if (self->f20 < 10) {
                    self->f20 = self->f20 + 1;
                    return;
                }
                if (func_0206b628(self, func_0205d060(&data_021027f8, 0x20, 4), 0) == 0) {
                    return;
                }
                func_0206b3e4(self, 0);
                return;
            } else {
                self->f20 = 0;
            }
        } else {
            self->f20 = 0;
        }
    }
}
