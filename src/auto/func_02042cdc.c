#include "m2c.h"

/* The function is variadic: the prologue "push {r0, r1, r2, r3}" is MWCC's
   argument home area, created only for variadic functions.  The three
   arguments are r0 = dst, r1 = src and r2 = the third argument.

   The third argument is a 4 byte aggregate, so MWCC keeps it in its home
   slot ([sp+8]) instead of allocating a register for it; the callee therefore
   reloads it with "ldr r2, [sp, #8]" rather than using r2 directly. */

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 z;
} ZVec;

void func_02042cdc(Vec3 *dst, Vec3 *src, ZVec v, ...) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = v.z;
}
