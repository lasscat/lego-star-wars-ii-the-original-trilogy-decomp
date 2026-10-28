#include "m2c.h"

typedef struct Ring {
    u8 *data;
    u32 pos;
    u32 size;
    u8 hist[0x20];
    u8 wide;
} Ring;

typedef struct Filt {
    u8 kind;
    u8 pad[0xB];
    s16 coeff[1];
} Filt;

void *func_0205e624(void *, u32, u32);
s32 func_0205e6e0(s32, s32, s32);
void func_020ba6cc(void *, s32, u32);
void func_02000e0c(void *, void *, u32, void *, void *);
void func_02001070(void *, void *, u32, void *, void *);
void func_020ba2ac(s16 *, s16 *, u32, s16 *, s16 *);
void func_020ba3b8(s8 *, s8 *, u32, s16 *, s8 *);

/*
 * Filters `count` samples of the ring buffer `r` in place, starting at r->pos
 * (16-bit samples when r->wide == 1, else 8-bit). If the run reaches the end of
 * the buffer, the part before the end is filtered here and the rest is handled
 * by a recursive call after r->pos wraps to 0. kind < 2 uses func_02000e0c /
 * func_02001070; other kinds use the 5-coefficient IIR filters func_020ba2ac /
 * func_020ba3b8, which keep their state in r->hist. Afterwards r->hist is
 * rebuilt from the last n samples (old history plus func_020ba6cc output).
 */
void func_020ba4b8(Filt *f, Ring *r, u32 count) {
    u8 tmp[0x20];
    u32 elem;
    u32 chunk;
    u32 rest;
    u32 off;
    u8 *base;
    u32 n;
    u8 *p;

    elem = (r->wide == 1) ? 2 : 1;
    func_0205e624(tmp, 0, 0x20);
    if (f->kind < 2) {
        n = 0x10;
    } else if (f->kind < 7) {
        n = 3;
    }
    base = r->data;
    off  = r->pos * elem;
    if (r->pos + count >= r->size) {
        chunk  = r->size - r->pos;
        r->pos = 0;
        rest   = count - chunk;
    } else {
        r->pos = r->pos + count;
        chunk  = count;
        rest   = 0;
    }
    p = tmp;
    if (count < n) {
        if (r->wide == 1) {
            u32 i;
            for (i = 0; i < n - count; i++) {
                *(s16 *) p = ((s16 *) r->hist)[count + i];
                p += 2;
            }
            func_020ba6cc(r, (s32) p, count);
        } else {
            u32 m = n - count;
            u32 step =
                sizeof(s8); // FAKE: stride in a local keeps (count + j) * step unfolded until after address reassociation
            u32 j;
            for (j = 0; j < m; j++) {
                *(s8 *) p = ((s8 *) r->hist)[(count + j) * step];
                p += step;
            }
            func_020ba6cc(r, (s32) p, count);
        }
    } else {
        func_020ba6cc(r, (s32) p, n);
    }
    if (f->kind < 2) {
        if (r->wide == 1) {
            func_02000e0c(base + off, base + off, chunk, f->coeff, r->hist);
        } else {
            func_02001070(base + off, base + off, chunk, f->coeff, r->hist);
        }
    } else {
        if (r->wide == 1) {
            func_020ba2ac((s16 *) (base + off), (s16 *) (base + off), chunk, f->coeff, (s16 *) r->hist);
        } else {
            func_020ba3b8((s8 *) (base + off), (s8 *) (base + off), chunk, f->coeff, (s8 *) r->hist);
        }
    }
    func_0205e6e0((s32) r->hist, (s32) tmp, n * elem);
    if (f->kind >= 3 && f->kind < 7) {
        func_020ba6cc(r, (s32) (r->hist + elem * 3), 2);
    }
    if (rest != 0) {
        func_020ba4b8(f, r, rest);
    }
}
