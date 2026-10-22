/* Reconstructed from USA ARM9 at 0x020a0630 (880 bytes). */
#include "engine.h"
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} S_020a0630_Vec;

typedef struct {
    u8 pad0[0x4c];
    S_020a0630_Vec f4c;
    u16 f58;
    u16 f5a;
    u16 f5c;
} S_020a0630_Big;

typedef struct {
    u8 pad00[0x28];
    S_020a0630_Vec f28;
    u8 pad34[0xc];
    u16 f40;
    u16 f42;
    u16 f44;
    u8 pad46[0x192];
    S_020a0630_Vec f1d8;
    u8 pad1e4[0x18];
    u32 f1fc;
    u8 pad200[0x3f];
    u8 f23f;
    u8 f240;
    u8 pad241[0x1f];
    S_020a0630_Vec *p260;
    u8 pad264[0x9c];
    S_020a0630_Big f300;
} S_020a0630_Self;

extern u32 data_02109358[];
extern u8 data_021027f8[];

void func_020aaad4(S_020a0630_Self *);
void func_020a4830(S_020a0630_Self *);
void func_020aa76c(S_020a0630_Self *, void *);
void func_020a2530(S_020a0630_Self *);
void func_020a2440(S_020a0630_Self *);
void func_020a210c(S_020a0630_Self *);
void func_020a0ec4(S_020a0630_Self *);
void func_020a2c9c(S_020a0630_Self *);
void func_020a34bc(S_020a0630_Self *);
void func_020a9a30(S_020a0630_Self *);
void func_020a41f4(S_020a0630_Self *);
void func_020aa794(S_020a0630_Self *, void *);
void func_020a3a48(S_020a0630_Self *, void *);
void func_020a1b64(S_020a0630_Self *, void *);
void func_020a16ac(S_020a0630_Self *);
void func_020a0c9c(S_020a0630_Self *);
void func_020a1450(S_020a0630_Self *);
void func_020a09a0(S_020a0630_Self *);
void func_020a0478(S_020a0630_Self *);

void func_020a0630(S_020a0630_Self *self, void *unused, u32 arg) {
    volatile u16 v0;
    volatile u16 v1;
    volatile u16 v2;
    u8 sel;

    self->f1fc = data_02109358[arg & 0xff];
    {
        S_020a0630_Vec *src = &self->f28;
        if (&self->f300.f4c != src) {
            self->f300.f4c.x = src->x;
            self->f300.f4c.y = src->y;
            self->f300.f4c.z = src->z;
        }
    }
    {
        u16 a          = self->f40;
        self->f300.f58 = a;
        v0             = a;
    }
    {
        u16 b          = self->f42;
        self->f300.f5a = b;
        v1             = b;
    }
    {
        u16 c          = self->f44;
        self->f300.f5c = c;
        v2             = c;
    }
    sel = *(u8 *) ((u8 *) self + arg + 0x208);
    switch (sel) {
        case 1:
            func_020aaad4(self);
            func_020a4830(self);
            func_020aa76c(self, &self->f1d8);
            func_020a2530(self);
            func_020a2440(self);
            func_020a210c(self);
            func_020a0ec4(self);
            func_020a2c9c(self);
            func_020a34bc(self);
            break;
        case 12:
            func_020a9a30(self);
            break;
        case 2:
            func_020a41f4(self);
            break;
        case 3: {
            S_020a0630_Vec v;
            v.x = 0;
            v.y = 0;
            v.z = 0;
            func_020aa794(self, &v);
            func_020a3a48(self, &v);
            func_020a210c(self);
            break;
        }
        case 4: {
            S_020a0630_Vec v;
            func_020aaad4(self);
            v.x = 0;
            v.y = 0;
            v.z = 0;
            func_020aa794(self, &v);
            func_020a1b64(self, &v);
            func_020aa76c(self, &self->f1d8);
            func_020a2530(self);
            func_020a2440(self);
            func_020a210c(self);
            func_020a0ec4(self);
            func_020a34bc(self);
            break;
        }
        case 5:
            func_020aaad4(self);
            func_020a1a0c(self);
            func_020aa76c(self, &self->f1d8);
            func_020a2530(self);
            func_020a2440(self);
            func_020a210c(self);
            func_020a34bc(self);
            break;
        case 6:
            func_020a16ac(self);
            break;
        case 7:
            if (self->p260 != 0) {
                func_020a3a48(self, self->p260);
            } else {
                S_020a0630_Vec v;
                v.x = 0;
                v.y = 0;
                v.z = 0;
                func_020aa794(self, &v);
                func_020a3a48(self, &v);
            }
            break;
        case 8:
            if (self->p260 != 0) {
                func_020a1b64(self, self->p260);
                {
                    S_020a0630_Vec *src = self->p260;
                    if (&self->f1d8 != src) {
                        self->f1d8.x = src->x;
                        self->f1d8.y = src->y;
                        self->f1d8.z = src->z;
                    }
                }
                func_020a34bc(self);
            } else {
                S_020a0630_Vec v;
                func_020aaad4(self);
                v.x = 0;
                v.y = 0;
                v.z = 0;
                func_020aa794(self, &v);
                func_020a1b64(self, &v);
                func_020aa76c(self, &self->f1d8);
                func_020a2530(self);
                func_020a2440(self);
                func_020a0ec4(self);
                func_020a34bc(self);
            }
            break;
        case 9:
            func_020a0c9c(self);
            func_020a1450(self);
            func_020a0ec4(self);
            func_020a2c9c(self);
            break;
        case 10:
            func_020a09a0(self);
            func_020a2c9c(self);
            break;
    }
    if (self->f23f != 0) {
        self->f23f = 0;
    }
    if (self->f240 != 0) {
        self->f240 = 0;
    }
    if (arg == data_021027f8[0x2a]) {
        func_020a0478(self);
    }
}
