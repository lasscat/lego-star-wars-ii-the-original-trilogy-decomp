#include "m2c.h"

typedef struct {
    u8 x;
    u8 y;
    u8 cols;
    u8 rows;
} P4;

enum {
    BLOCK_W = 0x20
};

/* Copies a p.cols x p.rows block of u16 entries from src (row stride n, origin p.x, p.y)
 * into the 32-entry-wide map at base, at column hdr[0] / row hdr[1], storing
 * add + entry + (add2 << 12). Columns past 32 go to base + 0x3e0 when mode is 1 or 3,
 * rows past 32 continue below when mode is 2 or 3, and the corner part runs when mode is 3. */
void func_0205435c(u16 *src, s32 n, u16 *base, s32 mode, P4 p, s16 *hdr, u32 add, u32 add2) {
    u16 *s;
    s32 cols;
    s32 h;
    s32 y;
    s32 off;
    s32 rows;
    u16 *d;
    s32 j;
    s32 i;
    s32 w;
    s32 t;

    y   = p.y;
    d   = base;
    off = y * n;
    s   = src + (p.x + off);
    d += hdr[0] + hdr[1] * BLOCK_W;
    cols = p.cols;
    w    = BLOCK_W - hdr[0];
    if (cols < w) {
        w = cols;
    }
    rows = p.rows;
    h    = BLOCK_W - hdr[1];
    if (rows < h) {
        h = rows;
    }
    if (w > 0 && h > 0) {
        for (i = h; i > 0; i--) {
            for (j = w; j > 0; j--) {
                *d = add + (*s + (add2 << 12));
                d++;
                s++;
            }
            d += BLOCK_W - w;
            s += n - w;
        }
    }
    if (hdr[0] + cols >= BLOCK_W && (mode == 1 || mode == 3)) {
        d = base + 0x3e0 + hdr[1] * BLOCK_W;
        w = cols - w;
        if (w >= BLOCK_W) {
            w = BLOCK_W;
        }
        if (hdr[0] < BLOCK_W) {
            s = src + BLOCK_W - hdr[0];
        } else {
            s = src + off + p.x;
            d += hdr[0];
        }
        for (i = h; i > 0; i--) {
            for (j = w; j > 0; j--) {
                *d = add + (*s + (add2 << 12));
                d++;
                s++;
            }
            d += BLOCK_W - w;
            s += n - w;
        }
        d += p.x;
    }
    if (hdr[1] + rows >= BLOCK_W && (mode == 2 || mode == 3)) {
        s = src + (y + h) * n + p.x;
        w = BLOCK_W - hdr[0];
        if (cols < w) {
            w = cols;
        }
        h = rows - h;
        if (h >= BLOCK_W) {
            h = BLOCK_W;
        }
        for (i = h; i > 0; i--) {
            for (j = w; j > 0; j--) {
                *d = add + (*s + (add2 << 12));
                d++;
                s++;
            }
            d += BLOCK_W - w;
            s += n - w;
        }
    }
    if (hdr[0] + cols < BLOCK_W) {
        return;
    }
    if (hdr[1] + rows < BLOCK_W) {
        return;
    }
    if (mode != 3) {
        return;
    }
    d += (BLOCK_W - h) * BLOCK_W - hdr[0];
    s += -h * n + w;
    t = (cols - w >= BLOCK_W) ? BLOCK_W : cols - w;
    for (i = h; i > 0; i--) {
        for (j = t; j > 0; j--) {
            *d = add + (*s + (add2 << 12));
            d++;
            s++;
        }
        d += BLOCK_W - t;
        s += n - t;
    }
}
