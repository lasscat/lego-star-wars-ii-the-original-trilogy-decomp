#include "m2c.h"

typedef struct {
    u16 mode;
    u16 pad;
    u32 result;
    u64 input;
} CPRegs;

typedef struct {
    s16 x, y, z;
} Pt16;

typedef struct {
    s32 v;
} Fx;

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline Fx fx(s32 v) {
    Fx r = {v};
    return r;
}

static inline s32 fx_mul_fx(s32 a, Fx b) {
    return fx_mul(a, b.v);
}

/* hardware square-root unit registers */
enum {
    SQRTCNT     = 0x040002b0,
    SQRT_RESULT = 0x040002b4
};
enum {
    SQRTCNT_BUSY = 0x8000
};
enum {
    FX32_ONE = 0x1000
};

extern Pt16 *func_02067b48(void *, s32);
extern u8 func_02067b54(void *);

/* Sums the lengths of the path's segments (point i-1 to point i; hardware sqrt of the squared
 * fx32 delta) into *out. */
void func_020a5c68(s32 *out, void *self, void *path) {
    u8 i;
    Pt16 *prev;
    Pt16 *cur;
    s64 d;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 len;
    *out = 0;
    for (i = 1; i < func_02067b54(path); i++) {
        prev = func_02067b48(path, i - 1);
        cur  = func_02067b48(path, i);
        dy   = prev->y << 12;
        dx   = prev->x << 12;
        dz   = prev->z << 12;
        dz   = (cur->z << 12) - dz;
        dx   = (cur->x << 12) - dx;
        dy   = (cur->y << 12) - dy;
        d    = (s64) dx * dx;
        d += (s64) dy * dy;
        d += (s64) dz * dz;
        ((CPRegs *) SQRTCNT)->mode  = 1;
        ((CPRegs *) SQRTCNT)->input = d << 2;
        while (((volatile CPRegs *) SQRTCNT)->mode & SQRTCNT_BUSY) {
        }
        len = (*(volatile s32 *) SQRT_RESULT + 1) >> 1;
        if (len < 0) {
            len = fx_mul_fx(len, fx(-FX32_ONE));
        }
        *out += len;
    }
}
