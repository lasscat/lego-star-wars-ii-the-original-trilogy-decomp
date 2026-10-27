#include "m2c.h"

extern s32 FX_Div(s32, s32);
void func_0208c674(s32 *, u32);
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104dc4;

enum {
    FX_100   = 0x64000, // 100.0 in 20.12 fixed point
    PCT_MAX  = 100,
    PCT_DIV  = 101,
    SEG_STEP = 10,
    SEG_MAX  = 9,
};

typedef struct {
    u8 pad0[0xd4];
    u32 *flags_owner;
    u16 *tbl;
    s32 num;
    s32 den;
} Obj;

// Fills a row of ten 16-bit entries (two parallel rows, +0x68 and +0xa8 bytes into the table at
// self->tbl): a 0..100 value from num/den is split into one 0..9 level per step of 10 and each
// level selects an entry from the same table. Over 100 sets bit 0 of flags_owner[2] and calls func_0208c674.
void func_02087e14(Obj *self) {
    struct {
        s32 a;
        s32 b;
        u8 d[10];
    } L;
    u8 *dp;
    u16 *dst;
    s32 pct;
    u32 i;
    s64 t;
    s32 q;
    u8 *p;

    dst  = self->tbl;
    p    = L.d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    q    = FX_Div(self->num << 12, self->den << 12);
    L.a = L.b = FX_100; // FAKE: dead stores keep two 100.0 (20.12) stack slots, as in the original frame
    t         = (s64) q * L.a + 0x800;
    pct       = (s32) (t >> 12) >> 12;
    if (pct > PCT_MAX) {
        self->flags_owner[2] |= 1;
        pct = PCT_MAX;
        func_0208c674(&data_02104dc4, *(u8 *) (*(s8 **) ((s8 *) &data_0210930c + 0x68) + 0x47a));
    }
    // The hardware divider (0x04000280) yields the remainder of pct / 101, capped at SEG_MAX.
    dp = L.d;
    do {
        M2C_FIELD((void *) 0x04000280, volatile u16 *, 0)    = 0;
        M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x10) = pct;
        M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x18) = PCT_DIV;
        M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x1c) = 0;
        while (M2C_FIELD((void *) 0x04000280, volatile u16 *, 0) & 0x8000) {
        }
        *dp = M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x28);
        if (*dp > SEG_MAX) {
            *dp = SEG_MAX;
        }
        pct -= SEG_STEP;
        dp++;
    } while (pct > 0);
    dst[0x34] = self->tbl[L.d[0] + 0x340];
    dst[0x54] = self->tbl[L.d[0] + 0x360];
    p         = &L.d[1];
    for (i = 1; i < 9; i++) {
        dst[0x34 + i] = self->tbl[*p + 0x380];
        dst[0x54 + i] = self->tbl[*p++ + 0x3a0];
    }
    dst[0x3d] = self->tbl[L.d[9] * 2 + 0x3c0];
    dst[0x5d] = self->tbl[L.d[9] * 2 + 0x3e0];
    dst[0x3e] = self->tbl[L.d[9] * 2 + 0x3c1];
    dst[0x5e] = self->tbl[L.d[9] * 2 + 0x3e1];
}
