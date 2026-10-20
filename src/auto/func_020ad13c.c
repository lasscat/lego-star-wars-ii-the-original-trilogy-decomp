#include "m2c.h"

/* The prologue "push {r0, r1, r2, r3}" is MWCC's argument home area, created
 * only for variadic functions.  The third argument is a 4 byte aggregate, so
 * MWCC keeps it in its home slot ([sp+0x10]) instead of a register and the
 * callee reloads it from there.
 *
 * The field at +0x158 is read through a volatile pointer, so the second read
 * inside the branch cannot be folded into the first one and the comparison
 * survives.  The volatile local "t" gives the 4 byte stack slot that holds
 * the value which is written back to +0x158 at the end. */
typedef struct {
    s32 v;
} Val;

void func_020ad13c(s32 *out, s32 *p, Val a2, ...) {
    volatile s32 t;
    s32 b;

    *out = *(s32 *) ((char *) p + 0x154);
    b    = *(volatile s32 *) ((char *) p + 0x158);
    t    = b;
    if (*(s32 *) ((char *) p + 0x154) == a2.v) {
        if (*(s32 *) ((char *) p + 0x158) == b) {
            return;
        }
    }
    *(s32 *) ((char *) p + 0x154)          = a2.v;
    *(volatile s32 *) ((char *) p + 0x158) = t;
    *(s32 *) ((char *) p + 0x160)          = -1;
}
