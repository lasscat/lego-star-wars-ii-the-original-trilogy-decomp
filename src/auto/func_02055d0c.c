#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02055d0c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb   sp!, {r4}
    mov     ip, #0x0
L_02055d14:
    cmp     ip, r3
    ldrlth  r4, [r0, ip]
    strlth  r4, [r1, ip]
    strlth  r4, [r2, ip]
    addlt   ip, ip, #0x2
    blt     L_02055d14
    ldmia   sp!, {r4}
    bx      lr
}
// clang-format on
