#include "m2c.h"

typedef struct {
    u8 x;
    u8 y;
    u8 cols;
    u8 rows;
} P4;

void func_020541dc(u16 *src, s32 srcWidth, u16 *dst, s32 shift, P4 p, s16 *hdr, u32 add, u32 add2, u32 add3) {
    s32 j;
    s32 i;
    u16 *d;
    u16 *s;
    s32 srcSkip;
    s32 dstSkip;

    dstSkip = (16 << shift) - p.cols;
    srcSkip = srcWidth - p.cols;
    d       = dst + hdr[1] * (16 << shift) + hdr[0];
    s       = src + p.y * srcWidth + p.x;
    for (i = 0; i < p.rows; i++) {
        for (j = 0; j < p.cols; j++) {
            *d = add + (*s + (add2 << 12));
            d++;
            s++;
        }
        d += dstSkip;
        s += srcSkip;
    }
}
