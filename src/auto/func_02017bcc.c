#include "m2c.h"

void func_02007f24(s32 *, double);
void func_02017ee4(void *, void *, s32);
void func_02018414(s32 *);
extern u8 data_020ff9b4[];

typedef struct Obj {
    u8 pad0[8];
    u32 flags;
    u8 pad0c[0x2c - 0xc];
    u8 *target;
    u8 pad30[0x40 - 0x30];
    u8 a;
    u8 b;
    u8 pad42[0x54 - 0x42];
    u8 *link;
    u8 pad58[0x60 - 0x58];
    s32 vx;
    s32 vy;
    s32 vz;
} Obj;

static inline s32 fxmul(s32 a, s32 b) {
    return (s32) (((s64) a * (s64) b + 0x800) >> 12);
}

void func_02017bcc(Obj *self) {
    u8 *l;
    s32 dec;
    s32 has;
    u8 *t;

    if (self->a != 0 && self->b != 0) {
        l = self->link;
        if (l != 0) {
            l = l - 4;
        }
        if (l == 0) {
            self->a = 0;
        }
    }
    if ((self->flags & 0x20) == 0x20) {
        if (self->a == 0) {
            if (self->vy > -0x5000) {
                func_02007f24(&dec, 0.115);
                self->vy -= dec;
                if (self->vy < -0x5000) {
                    self->vy = -0x5000;
                }
            }
        } else {
            func_02018414(&self->vy);
        }
    }
    has = 0;
    t   = self->target;
    if (t != 0 && t[0x26] != 0) {
        has = 1;
    }
    if (has != 0) {
        func_02017ee4(self, t + 4, 0x4b);
        return;
    }
    if ((self->flags & 0x200) == 0x200) {
        func_02017ee4(self, data_020ff9b4, 0xc0);
        if (fxmul(self->vx, self->vx) + fxmul(self->vz, self->vz) < 0x40) {
            self->vx = 0;
            self->vz = 0;
        }
    }
}
