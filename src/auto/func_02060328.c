#include "m2c.h"

/*
 * func_02060328: fills the 192 16-byte entries at +0x24 of the object
 * (caller func_02084348 runs it right after func_020602ec stored the
 * angle at +0xc28 and func_0206024c stored the position at +0x08/+0x0c).
 *
 * With cs/sn = cos/sin of the +0xc28 angle (data_020f88c4 holds {sin, cos}
 * s16 pairs per 16 angle units) and, per entry i,
 *   ang = f26 + f24 / 2 - i * (f24 / 192),
 *   q   = FX_Div(fx_mul(FX_Div(f18, cos(ang)), cos(ang - f26)), f20),
 * the entry gets a = d = cs * q, b = sn * q, c = -b and the position minus
 * the (128.0, 96 - i) * q offset rotated by (cs, sn); every value is rounded
 * from 20.12 to 4 fraction bits ((v + 8) >> 4).
 *
 * Shape notes: the Ang/Fx struct copies give the stack slots and the
 * post-loop write-backs; the in-place s64 fx_mul is needed for the
 * (96 - i) product; the statement order (stores after the a/b/128.0
 * products, x stored before the z sum, z built in place) gives the
 * register colouring.
 */

typedef struct Ang {
    u16 v;
} Ang;

typedef struct Fx {
    s32 v;
} Fx;

typedef struct Entry {
    s16 a, b, c, d;
    s32 x, z;
} Entry;

typedef struct Obj {
    u8 pad0[0x8];
    s32 f08;
    s32 f0c;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1c[0x20 - 0x1c];
    Fx f20;
    Entry ent[192];
    u16 f24;
    u16 f26;
    u16 f28;
} Obj;

enum {
    ENTRY_COUNT = 192,
    MID_ENTRY   = 96,
    FX_128      = 0x80000
};

extern const s16 data_020f88c4[];
extern s32 FX_Div(s32, s32);

static inline s32 fx_mul(s32 a, s32 b) {
    s64 t = a;
    t     = (t * b + 0x800) >> 12;
    return (s32) t;
}

static inline Ang ang_make(u16 v) {
    Ang a;
    a.v = v;
    return a;
}

static inline s32 ang_sin(Ang a) {
    return data_020f88c4[(a.v >> 4) * 2];
}

static inline s32 ang_cos(Ang a) {
    return data_020f88c4[(a.v >> 4) * 2 + 1];
}

static inline s32 fx_div(s32 a, Fx b) {
    return FX_Div(a, b.v);
}

void func_02060328(Obj *o) {
    Ang a1;
    Ang a2;
    Ang yaw;
    Ang y2;
    Ang b1;
    Ang b2;
    Fx kk;
    Fx k1;
    s32 step;
    s32 cs, sn, i, q, v, w;
    s32 ip, aa, xx, zz;
    Entry *out;
    s32 ang, c;

    yaw  = ang_make(o->f28);
    y2   = yaw;
    cs   = ang_cos(yaw);
    sn   = ang_sin(y2);
    step = o->f24 / ENTRY_COUNT;
    out  = o->ent;
    for (i = 0; i < ENTRY_COUNT; i++) {
        c    = o->f26;
        ang  = c + o->f24 / 2 - i * step;
        a1.v = ang;
        b1   = a1;
        q    = FX_Div(o->f18, ang_cos(b1));
        a2.v = ang - c;
        b2   = a2;
        kk.v = ang_cos(b2);
        k1   = kk;
        q    = fx_div(fx_mul(q, k1.v), o->f20);

        w      = (fx_mul(cs, q) + 8) >> 4;
        v      = (fx_mul(sn, q) + 8) >> 4;
        aa     = fx_mul(FX_128, q);
        out->a = w;
        out->b = v;
        out->c = -v;
        out->d = w;
        ip     = fx_mul((MID_ENTRY - i) << 12, q);
        xx     = fx_mul(aa, cs) + fx_mul(ip, sn);
        out->x = ((o->f08 + 8) >> 4) - ((xx + 8) >> 4);
        zz     = fx_mul(ip, cs);
        zz -= fx_mul(aa, sn);
        out->z = ((o->f0c + 8) >> 4) - ((zz + 8) >> 4);
        out++;
    }
}
