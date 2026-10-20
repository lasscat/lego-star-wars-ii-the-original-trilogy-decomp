#include "m2c.h"

extern void func_02062ae4();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202925c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    ldr     r0, =0xffff
    bl      func_02062ae4
    ldr r1, [sp, #0x8]
    cmp r1, r0, lsl #0xc
    movgt r0, #0x1
    movle r0, #0x0
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
