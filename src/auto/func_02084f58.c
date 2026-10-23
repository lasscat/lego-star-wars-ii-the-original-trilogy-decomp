/* Reconstructed from USA ARM9 at 0x02084f58 (880 bytes). */
#include "engine.h"
#include "m2c.h"

struct S_02084f58_Data {
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
    u8 pad0;
    u8 b;
    u16 s;
    u8 pad4[8];
} S_02084f58_Elem;

typedef struct {
    u8 pad0[0x8];
    u32 f8;
    u8 padc[0x88];
    s32 f94;
} S_02084f58_Sub;

typedef struct {
    u8 pad[0x20];
    s32 f20;
} S_02084f58_Owner;

typedef struct {
    s32 a;
    u8 pad[0x18];
} S_02084f58_Tmp;

typedef struct {
    u8 pad00[0x4];
    S_02084f58_Owner *p04;
    u16 f08;
    u8 pad0a[0x2];
    void *p0c;
    u8 pad10[0xc];
    s32 f1c;
    s32 f20;
    S_02084f58_Sub *p24;
    S_02084f58_Sub *p28;
    S_02084f58_Sub *p2c;
    S_02084f58_Elem arr[8];
} S_02084f58_Self;

extern struct S_02084f58_Data data_021044a4;
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104d90;
extern u32 data_027e02a8;
extern M2C_UNK data_0210794c;

s32 func_02064a58(void *, void *);
void func_020b8f70(s32, s32);
s32 func_0205cfe8(void *, void *, s32, s32, s32);
s32 func_0205d0d0(void *, s32, s32);
s32 func_02086740(void *, s32);
void func_020b04f0(void *, s32, void *, s32);
void func_02086810(void *, s32, s32);
void func_02065600(void *, s32);
void func_020852c8(void *);

void func_02084f58(S_02084f58_Self *self) {
    s32 f5  = 0;
    s32 f6  = 0;
    s32 f11 = 0;
    u16 loc[2];
    s32 prev = self->f1c;
    u32 i;
    s32 ok;

    loc[0] = 0;
    loc[1] = 0;
    if (data_021044a4.b2) {
        loc[0] = data_021044a4.f2a;
        loc[1] = data_021044a4.f2c;
    }
    for (i = 0; i < 8; i++) {
        if (func_02064a58(&self->arr[i], loc) == 0) {
            continue;
        }
        {
            u32 t = i + self->f20;
            if ((self->f1c == t && self->arr[i].b != 0) || (s32) self->arr[i].s >= 10) {
                f6 = 1;
            } else if (self->f1c != t && self->arr[i].b != 0) {
                func_020b8f70(0xb6, 0);
                self->f1c = t;
                f5        = 1;
            }
        }
        f11 = 1;
        break;
    }
    if (f11 == 0) {
        ok = 1;
        if (self->p24->f94 != 1 && self->p28->f94 != 1) {
            ok = 0;
        }
        if (ok && data_021044a4.b5) {
            if (self->p24->f94 == 1) {
                s32 v = self->f1c - 1;
                if (v < 0) {
                    v = 0x11;
                }
                self->f1c = v;
            } else if (self->p28->f94 == 1) {
                s32 v = self->f1c + 1;
                if (v == 0x12) {
                    v = 0;
                }
                self->f1c = v;
            }
        } else {
            ok = 0;
        }
        if (ok || func_0205cfe8(&data_021027f8, &self->f1c, 0, 0x12, 4)) {
            u32 st = self->f1c;
            if (st == 0 && prev == 0x11) {
                self->f20 = 0;
            } else if (st == 0x11 && prev == 0) {
                self->f20 = 0xa;
            } else {
                u32 t = self->f20;
                if (st >= t + 8) {
                    self->f20 = t + 1;
                } else if (st < t) {
                    self->f20 = t - 1;
                }
            }
            func_020b8f70(0xb6, 0);
            f5 = 1;
        } else {
            if (func_0205d0d0(&data_021027f8, 0x30, 4)) {
                f6 = 1;
            } else if (func_0205d0d0(&data_021027f8, 2, 4) || (self->p2c->f94 == 1 && data_021044a4.b5)) {
                self->p24->f8 &= ~1;
                self->p28->f8 &= ~1;
                self->p2c->f8 &= ~1;
                func_020b8f70(0xb5, 0);
                self->f08 |= 1;
                self->p04->f20 |= 4;
                func_02065600(self->p0c, 4);
                return;
            }
        }
    }
    if (f6) {
        if (func_02086740(&data_02104d90, self->f1c) != 0) {
            func_020b8f70(0xb4, 0);
            if (data_027e02a8 & 0x40) {
                S_02084f58_Tmp v;
                v.a = self->f1c;
                func_020b04f0(&data_0210794c, 0x36, &v, 0xff);
            } else {
                func_02086810(&data_02104d90, self->f1c, 1);
            }
            f5 = 1;
        } else {
            func_020b8f70(0xb7, 0);
        }
    }
    if (!f5) {
        return;
    }
    func_020852c8(self);
}
