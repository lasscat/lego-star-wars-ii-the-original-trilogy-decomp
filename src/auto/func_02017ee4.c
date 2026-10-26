#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad0c[0x34];
    u8 sub40[0x20];
    s32 x60;
    s32 pad64;
    s32 z68;
} Obj;

s32 func_0204fa30(u8 *p);
s32 func_020867ec(M2C_UNK *, s32);
extern M2C_UNK data_02104d90;

static inline s32 fxmul(s32 x, s32 n) {
    return (s32) (((s64) x * (s64) (n << 12) + 0x800) >> 12);
}
static inline s32 fxmul2(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

void func_02017ee4(Obj *self, Vec3 *vec, s32 blend) {
    if ((func_0204fa30(self->sub40) == 4 && (self->flags & 0x8000000) != 0x8000000) || func_020867ec(&data_02104d90, 0) != 0) {
        blend = 8;
    }
    self->x60 = (fxmul(self->x60, 0x100 - blend) + fxmul(vec->x, blend)) >> 8;
    self->z68 = (fxmul(self->z68, 0x100 - blend) + fxmul(vec->z, blend)) >> 8;
}
