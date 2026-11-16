#include "m2c.h"

extern const s16 data_020f88c4[];
extern s32 data_020ff9b4[3];
s32 func_02062ab4(s32, s32);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    u16 v;
} Ang;

/* Binary angle units: 0x10000 is a full turn; the top 12 bits index the
 * interleaved {sin, cos} table (20.12 fixed point). */
enum {
    HALF_TURN = 0x8000,
    FULL_TURN = 0xFFFF
};

static inline void setang(Ang *p, s32 lo, s32 hi) {
    p->v = func_02062ab4(lo, hi);
}

static inline void rotX(V3 *v, Ang ang) {
    s32 s, c, y, z, ny, t;
    int i;
    i = ang.v >> 4;
    i *= 2;
    s  = data_020f88c4[i];
    c  = data_020f88c4[i + 1];
    y  = v->y;
    z  = v->z;
    t  = (s32) (((s64) z * s + 0x800) >> 12);
    ny = (s32) (((s64) y * c + 0x800) >> 12);
    ny -= t;
    v->y = ny;
    v->z = (s32) (((s64) y * s + 0x800) >> 12);
    t    = (s32) (((s64) z * c + 0x800) >> 12);
    t += v->z;
    v->z = t;
}

static inline void rotY(V3 *v, Ang ang) {
    s32 s, c, x, z, nx, t;
    int i;
    i = ang.v >> 4;
    i *= 2;
    s  = data_020f88c4[i];
    c  = data_020f88c4[i + 1];
    x  = v->x;
    z  = v->z;
    t  = (s32) (((s64) z * s + 0x800) >> 12);
    nx = (s32) (((s64) x * c + 0x800) >> 12);
    nx += t;
    v->x = nx;
    v->z = (s32) (((s64) x * s + 0x800) >> 12);
    t    = (s32) (((s64) z * c + 0x800) >> 12);
    t -= v->z;
    v->z = t;
}

static inline void rotB(V3 *v, Ang a, Ang *pb) {
    setang(pb, 0, FULL_TURN);
    {
        Ang bv = *pb;
        rotX(v, a);
        rotY(v, bv);
    }
}

/*
 * Virtual slot 0x04 of the table at data_02101190 (slot 0x08 is func_020bdcfc,
 * which fills spec + 0x68 / + 0x6c). Writes a vector to out: data_020ff9b4
 * with y replaced by a random value in [spec + 0x68, spec + 0x6c]
 * (func_02062ab4 returns a random integer in [lo, hi]), rotated about X by a
 * random angle in [0, HALF_TURN] and then about Y by a random angle in
 * [0, FULL_TURN].
 */
void func_020bdb40(V3 *out, void *spec) {
    Ang a, b;
    out->x = data_020ff9b4[0];
    out->y = data_020ff9b4[1];
    out->z = data_020ff9b4[2];
    out->y = func_02062ab4(M2C_FIELD(spec, s32 *, 0x68), M2C_FIELD(spec, s32 *, 0x6C));
    setang(&a, 0, HALF_TURN);
    rotB(out, a, &b);
}
