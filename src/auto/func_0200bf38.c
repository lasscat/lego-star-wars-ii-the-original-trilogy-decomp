#include "m2c.h"

typedef struct {
    s32 v0;
    s32 v4;
    s32 v8;
} Vec3;

typedef struct Unk0200bf38 {
    u8 pad_00[0xB0];
    Vec3 fB0;
    u8 pad_BC[0xD1 - 0xBC];
    u8 fD1;
    u8 pad_D2[0x1C8 - 0xD2];
    void *f1C8;
} Unk0200bf38;

void func_0200bf38(Unk0200bf38 *self, Vec3 *other) {
    s32 changed;
    Vec3 *dst;

    if ((self->fB0.v0 != other->v0) || (self->fB0.v4 != other->v4) || (self->fB0.v8 != other->v8)) {
        changed = 1;
    } else {
        changed = 0;
    }
    if (changed != 0) {
        if (&self->fB0 != other) {
            self->fB0.v0 = other->v0;
            self->fB0.v4 = other->v4;
            self->fB0.v8 = other->v8;
        }
        self->fD1 = 1;
    }
    dst = (Vec3 *) ((u8 *) self->f1C8 + 4);
    if (dst != other) {
        dst->v0 = other->v0;
        dst->v4 = other->v4;
        dst->v8 = other->v8;
    }
}
