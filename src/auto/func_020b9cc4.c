#include "m2c.h"

extern s8 data_020f8634[];
extern u16 data_020f8644[];

void func_020b9cc4(u8 *out, u8 *in, u32 count, u32 wide) {
    s32 i;
    s32 stepidx;
    u32 bits;
    s32 nib;
    s32 sample;
    s32 step;
    s32 diff;
    u8 shift;
    s32 lo = -0x8000;
    s32 hi = 0x7FFF;

    shift  = in[2];
    sample = *(s16 *) in;
    in += 4;
    stepidx = shift & 0x7f;
    step    = data_020f8644[stepidx];
    for (i = 0; i < count; i++) {
        if ((i & 7) == 0) {
            bits = *(u32 *) in;
            in += 4;
        }
        nib = bits & 0xf;
        bits >>= 4;
        diff = step >> 3;
        if (nib & 1) {
            diff += step >> 2;
        }
        if (nib & 2) {
            diff += step >> 1;
        }
        if (nib & 4) {
            diff += step;
        }
        if (nib & 8) {
            diff = -diff;
        }
        sample += diff;
        if (sample >= 0x8000) {
            sample = hi;
        } else if (sample < lo) {
            sample = lo;
        }
        if (wide) {
            ((u16 *) out)[i] = sample;
        } else {
            out[i] = sample >> 8;
        }
        stepidx += data_020f8634[nib];
        if (stepidx < 0) {
            stepidx = 0;
        } else if (stepidx > 0x58) {
            stepidx = 0x58;
        }
        step = data_020f8644[stepidx];
    }
}
