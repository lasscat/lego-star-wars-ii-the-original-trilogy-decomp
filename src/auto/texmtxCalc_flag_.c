#include "m2c.h"

/* texmtxCalc_flag_: builds the scaled/rotated texture matrix.
 * All products are 64-bit fixed point with a 1.12 scale, the two division
 * results come from the hardware divide unit (FX_DivAsync / FX_GetDivResult). */

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
} TexMtx;

typedef struct {
    s32 unused00;
    s32 unused04;
    s32 unused08;
    s32 unused0c;
    s32 unused10;
    s32 unused14;
    s32 scaleX;
    s32 scaleY;
    s16 rotSin;
    s16 rotCos;
    s32 transX;
    s32 transY;
    u16 width;
    u16 height;
} TexMat;

extern void FX_DivAsync(s32 numerator, s32 denominator);
extern s32 func_020c930c(void);

void texmtxCalc_flag_(TexMtx *out, TexMat *in) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 w12 = in->width << 12;
    s32 h12 = in->height << 12;

    FX_DivAsync(h12, w12);

    s1       = (s32) (((s64) in->scaleX * in->rotSin) >> 12);
    s0       = (s32) (((s64) in->scaleX * in->rotCos) >> 12);
    s2       = (s32) (((s64) in->scaleY * in->rotSin) >> 12);
    s3       = (s32) (((s64) in->scaleY * in->rotCos) >> 12);
    out->f00 = s0;
    out->f14 = s3;

    out->f04 = (s32) ((-s2 * func_020c930c()) >> 12);

    FX_DivAsync(w12, h12);

    out->f30 = (s32) (((s32) (in->width * (in->scaleX - (s1 + s0))) << 3) -
                      (s32) (in->width * (s32) (((s64) in->scaleX * in->transX) >> 8)));
    out->f34 = (s32) (((s32) (in->height * ((s2 - s3) - in->scaleY + 0x2000)) << 3) +
                      (s32) (in->height * (s32) (((s64) in->scaleY * in->transY) >> 8)));

    out->f10 = (s32) ((s1 * func_020c930c()) >> 12);
}
