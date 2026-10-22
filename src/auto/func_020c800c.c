#include "m2c.h"

typedef struct {
    void *f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
} Big;

typedef struct {
    u32 f00;
    u8 pad04[0x2c];
    s32 f30;
    s32 f34;
} Self;

typedef void (*Fn)(void *, void *);

extern void NNS_G3dGeBufferOP_N(void *, s32 *, s32);
extern Fn data_02101518[];

void func_020c800c(Self *self) {
    Big s;
    s32 sc30;
    s32 sc34;

    if (self->f00 & 8) {
        s.f00 = (void *) 0x101610;
    } else {
        s.f00 = (void *) 0x101810;
    }
    s.f04 = 3;
    s.f48 = 2;
    s.f40 = 0;
    s.f34 = 0;
    s.f30 = 0;
    s.f2c = 0;
    s.f28 = 0;
    s.f24 = 0;
    s.f20 = 0;
    s.f14 = 0;
    s.f10 = 0;
    s.f44 = 0x1000;

    data_02101518[self->f00 & 7]((void *) &s.f08, self);

    sc30 = self->f30;
    if (sc30 != 0x1000) {
        s.f08 = (s32) (((s64) sc30 * s.f08) >> 12);
        s.f0c = (s32) (((s64) sc30 * s.f0c) >> 12);
        s.f38 = (s32) (((s64) sc30 * s.f38) >> 12);
    }
    sc34 = self->f34;
    if (sc34 != 0x1000) {
        s.f18 = (s32) (((s64) sc34 * s.f18) >> 12);
        s.f1c = (s32) (((s64) sc34 * s.f1c) >> 12);
        s.f3c = (s32) (((s64) sc34 * s.f3c) >> 12);
    }
    NNS_G3dGeBufferOP_N(s.f00, (s32 *) ((u8 *) &s + 4), 0x12);
}
