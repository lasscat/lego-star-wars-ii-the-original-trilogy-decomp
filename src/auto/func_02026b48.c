#include "m2c.h"

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

void func_02010c6c(void *a0, s32 a1, s32 a2, s32 a3, u8 a4, void *a5, s32 a6, s32 a7);
extern const s16 data_020f88c4[]; /* interleaved {sin, cos} s16 table, one pair per 16 angle units (cf. func_0209b27c.c) */

/* fx32 (20.12) constants */
enum {
    FX_8  = 0x8000,
    FX_9  = 0x9000,
    FX_13 = 0xD000
};

/* fx32 multiply with 20.12 rounding; the s64 product is built in place in one temporary. */
static inline s32 FX_MUL(s32 a, s32 b) {
    s64 t = a;
    t     = (t * b + 0x800) >> 12;
    return (s32) t;
}

static inline s32 FX_SinIdx(int idx) {
    return data_020f88c4[(idx >> 4) << 1];
}
static inline s32 FX_CosIdx(int idx) {
    return data_020f88c4[((idx >> 4) << 1) + 1];
}

/*
 * Copies the vector at self+0xB0 into pos, offsets it by the u16 kind at self+0x212
 * (0x147: 13.0 along the angle at self+0x220 in x/z plus 9.0 in y; 0x2E: none; any other: 8.0 in y)
 * and passes &pos to func_02010c6c (kind 0x67 passes 0xE as the second argument, others 0).
 */
void func_02026b48(void *self, s32 arg1) {
    Vec3 pos;

    pos.x = M2C_FIELD(self, s32 *, 0xB0);
    pos.y = M2C_FIELD(self, s32 *, 0xB4);
    pos.z = M2C_FIELD(self, s32 *, 0xB8);
    switch ((u32) M2C_FIELD(self, u16 *, 0x212)) {
        case 0x147: {
            u16 ang = M2C_FIELD(self, u16 *, 0x220);
            s32 dx  = FX_MUL(FX_SinIdx(ang), FX_13);
            s32 dz  = FX_MUL(FX_CosIdx(ang), FX_13);
            pos.x += dx;
            pos.z += dz;
            pos.y += FX_9;
            break;
        }
        case 0x5E:
            pos.y += FX_8;
            break;
        case 0x67:
            pos.y += FX_8;
            func_02010c6c(self, 0xE, 0, 10, 4, &pos, arg1, 1);
            return;
        case 0x2F:
            pos.y += FX_8;
            break;
        case 0x90:
            pos.y += FX_8;
            break;
        case 0x2E:
            break;
        case 0xEA:
        case 0xEB:
        default:
            pos.y += FX_8;
            break;
    }
    func_02010c6c(self, 0, 0, 10, 4, &pos, arg1, 1);
}
