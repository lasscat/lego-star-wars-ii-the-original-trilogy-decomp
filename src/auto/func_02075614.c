#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02075614(s32 a0, s32 a1, s32 a2) {
    mov     ip, r1, lsr #0x5
    cmp     r2, #0x0
    and     r2, r1, #0x1f
    ldrne   r1, [r0, ip, lsl #0x2]
    mov     r3, #0x1
    orrne   r1, r1, r3, lsl r2
    mvneq   r1, r3, lsl r2
    ldreq   r2, [r0, ip, lsl #0x2]
    andeq   r1, r2, r1
    str     r1, [r0, ip, lsl #0x2]
    bx      lr
}
// clang-format on
