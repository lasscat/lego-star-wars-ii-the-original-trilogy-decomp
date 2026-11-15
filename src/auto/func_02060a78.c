/* Reconstructed from USA ARM9 at 0x02060a78 (204 bytes).
 *
 * Builds 2x2 rotation/scale matrices (12 bit fixed point) from an array of
 * 6 byte entries { s16 sx, s16 sy, u16 angle } and stores the four
 * results to the destination, `stride` bytes apart.
 *
 * The only caller (func_02060a2c) passes dst = 0x07000006 + n * 0x400 with
 * stride 8, i.e. the PA/PB/PC/PD slots of the OAM affine parameter groups.
 * data_020f88c4 holds interleaved { sin, cos } s16 pairs indexed by
 * (angle >> 4) * 2.
 */
#include "m2c.h"

extern const s16 data_020f88c4[];

typedef struct {
    s16 sx;
    s16 sy;
    u16 angle;
} Scale;

enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

void func_02060a78(Scale *src, char *dst, s32 count, s32 stride) {
    s16 sx;
    s16 sy;
    s16 c;
    s16 s;
    s32 idx;
    s32 i;

    for (i = 0; i < count; i++, src++) {
        sx           = src->sx;
        sy           = src->sy;
        idx          = (src->angle >> 4) * 2;
        *(s16 *) dst = fx_mul(c = data_020f88c4[idx + 1], sx);
        dst += stride;
        s            = data_020f88c4[idx];
        *(s16 *) dst = fx_mul(s, sx);
        dst += stride;
        *(s16 *) dst = fx_mul(-s, sy);
        dst += stride;
        *(s16 *) dst = fx_mul(c, sy);
        dst += stride;
    }
}
