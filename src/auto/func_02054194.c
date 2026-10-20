#include "m2c.h"

extern void func_02054178();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02054194(s32 a0, s32 a1) {
    stmdb   sp!, {r4, lr}
    sub     sp, sp, #0x8
    mov     r2, r0
    mov     r4, r1
    add     r0, sp, #0x0
    mov     r1, r2
    bl      func_02054178
    ldr     r1, [sp, #0x0]
    ldr     r0, [sp, #0x4]
    mov     r1, r1, asr #0xc
    mov     r0, r0, asr #0xc
    mul     r0, r1, r0
    cmp     r4, #0x0
    moveq   r0, r0, lsl #0x1
    add     r0, r0, #0x3
    bic     r0, r0, #0x3
    add     sp, sp, #0x8
    ldmfd   sp!, {r4, pc}
}
// clang-format on
