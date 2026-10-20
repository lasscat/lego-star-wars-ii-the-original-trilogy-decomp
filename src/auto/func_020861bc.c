#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020861bc(s32 arg0, s32 arg1, s32 arg2) {
    stmfd sp!, {r3, r4, r5, lr}
    add     r3, r0, #0x88
    and     lr, r1, #0x1f
    mov     r5, #0x1
    mov     r4, r1, asr #0x5
    add     ip, r3, #0x4400
    mvn     r1, r5, lsl lr
    ldr     r3, [ip, r4, lsl #0x2]
    cmp     r2, #0x0
    and     r1, r3, r1
    add     r0, r0, #0x88
    str     r1, [ip, r4, lsl #0x2]
    add     r1, r0, #0x4400
    ldr     r0, [r1, r4, lsl #0x2]
    moveq   r5, #0x0
    orr     r0, r0, r5, lsl lr
    str     r0, [r1, r4, lsl #0x2]
    ldmfd sp!, {r3, r4, r5, pc}
}
// clang-format on
