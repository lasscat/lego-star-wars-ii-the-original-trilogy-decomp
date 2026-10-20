#include "m2c.h"

typedef struct {
    u8 x;
    u8 y;
    u8 cols;
    volatile u8 rows;
} M2C_P4;

void func_0205427c(u8 *src, s32 n, s32 base, s32 shift, M2C_P4 p, s16 *hdr, u32 add) {
    u8 cols;
    s32 j;
    u8 *dst;
    s32 stride;
    s32 i;
    u8 rows;
    s32 pos;
    stride = 16 << shift;
    pos    = base + hdr[1] * stride;
    pos += hdr[0];
    cols = p.cols;
    rows = p.rows;
    for (i = rows; i > 0; i--) {
        j   = cols;
        dst = (u8 *) (pos & ~1);
        while (j > 0) {
            if (pos & 1) {
                u16 v        = *(u16 *) dst;
                *(u16 *) dst = (u16) ((v & 0xff) | ((src[0] << 8) + add));
            } else if (j == 1) {
                u16 v        = *(u16 *) dst;
                *(u16 *) dst = (u16) ((v & 0xff00) | (src[0] + add));
            } else {
                *(u16 *) dst = (u16) ((src[0] + add) | ((src[1] + add) << 8));
                pos++;
                src++;
                j--;
            }
            j--;
            dst += 2;
            pos++;
            src++;
        }
        pos += stride - n;
    }
}
