#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} VecFx;

extern s16 func_020985d8(s32, s32);
extern s32 func_0201eec4(s32 *, s32 *, UnkVal);
extern void func_0204a5f8(void *, u16 *);

static inline void vec_set(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline u16 fx_atan2(Fx x, Fx z) {
    return func_020985d8(x.v, z.v);
}

void func_0202abc8(void *self, void *ctx) {
    u16 yaw;
    VecFx d;
    UnkVal md;
    Fx qz;
    Fx qx;
    s32 done;

    done = 1;
    if (M2C_FIELD(ctx, u8 *, 0x40) == 0) {
        md.v = 0x5000;
        if (func_0201eec4((s32 *) ((u8 *) ctx + 0xb0), (s32 *) ((u8 *) self + 0x64), md) == 0) {
            done = 0;
        }
    }
    if (done != 0) {
        M2C_FIELD(self, u8 *, 0x8c) = 2;
        return;
    }
    vec_set((s32 *) &d, M2C_FIELD(self, s32 *, 0x64) - M2C_FIELD(ctx, s32 *, 0xb0),
            M2C_FIELD(self, s32 *, 0x68) - M2C_FIELD(ctx, s32 *, 0xb4),
            M2C_FIELD(self, s32 *, 0x6c) - M2C_FIELD(ctx, s32 *, 0xb8));
    qz  = d.z;
    qx  = d.x;
    yaw = fx_atan2(qx, qz);
    func_0204a5f8((u8 *) ctx + 0x5ce, &yaw);
    M2C_FIELD(ctx, u16 *, 0x5ce) |= 2;
    M2C_FIELD(ctx, u16 *, 0x5d2) =
        M2C_FIELD(ctx, u16 *, 0x5ce) & (M2C_FIELD(ctx, u16 *, 0x5ce) ^ M2C_FIELD(ctx, u16 *, 0x5d0));
    M2C_FIELD(ctx, u16 *, 0x5d4) =
        M2C_FIELD(ctx, u16 *, 0x5d0) & (M2C_FIELD(ctx, u16 *, 0x5ce) ^ M2C_FIELD(ctx, u16 *, 0x5d0));
}
