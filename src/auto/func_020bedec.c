#include "m2c.h"

/* A 12-byte entry: three 32-bit words. */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Tri;

extern Tri data_0210e9f4[64];
extern Tri data_020ff9b4[1];

/*
 * Copies the element held in data_020ff9b4 into slot a1[0x13] of the
 * table in data_0210e9f4.  If that slot already is data_020ff9b4 there is
 * nothing to do.
 */
void func_020bedec(s32 *a0, s32 *a1) {
    Tri *dst = &data_0210e9f4[a1[0x13]];
    if (dst != &data_020ff9b4[0]) {
        dst->a = data_020ff9b4[0].a;
        dst->b = data_020ff9b4[0].b;
        dst->c = data_020ff9b4[0].c;
    }
}
