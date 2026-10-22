#include "m2c.h"

void func_020ba2ac(s16 *in, s16 *out, u32 count, s16 *coeff, s16 *state) {
    s16 ins[3]  = {0, 0, 0};
    s16 outs[2] = {0, 0};
    u32 i;
    s16 s;
    s16 a;
    s16 b;
    s16 v;
    s32 acc;

    if (state != 0) {
        ins[0]  = state[2];
        ins[1]  = state[1];
        ins[2]  = state[0];
        outs[0] = state[4];
        outs[1] = state[3];
    }
    for (i = 0; i < count; i++) {
        s      = in[i];
        a      = ins[1];
        b      = ins[0];
        ins[2] = a;
        ins[1] = b;
        ins[0] = s;
        acc    = coeff[0] * ins[0];
        acc += coeff[1] * b;
        acc += coeff[2] * a;
        acc += coeff[3] * outs[0];
        acc += coeff[4] * outs[1];
        acc >>= 14;
        if (acc >= 32768) {
            acc = 32767;
        } else if (acc < -32768) {
            acc = -32768;
        }
        v       = (s16) acc;
        out[i]  = v;
        outs[1] = outs[0];
        outs[0] = v;
    }
}
