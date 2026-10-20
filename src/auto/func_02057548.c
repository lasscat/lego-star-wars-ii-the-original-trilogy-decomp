#include "m2c.h"

extern void func_020aaeb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057548(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0xc
    ldrh r3, [r1, #0x0]
    ldrb r2, [r1, #0x2]
    ldr     r1, =0xb60b60b7
    mov     ip, r3, lsl 0x10
    smull r0, lr, r1, ip
    add lr, lr, r3, lsl #0x10
    mov     r0, ip, lsr 0x1f
    add lr, r0, lr, asr #0x8
    strh lr, [sp, #0x2]
    ldrh r0, [sp, #0x2]
    str r2, [sp, #0x8]
    str r2, [sp, #0x4]
    strh r0, [sp, #0x0]
    bl      func_020aaeb4
    ldrh r3, [sp, #0x0]
    add r1, r0, #0x200
    ldr r2, [sp, #0x4]
    strh r3, [r1, #0x7a]
    str r2, [r0, #0x27c]
    add sp, sp, #0xc
    ldmia   sp!, {pc}
}
// clang-format on
