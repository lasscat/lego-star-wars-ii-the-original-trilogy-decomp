#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020ab65c(s32 a0, s32 a1) {
    ldr r2, [r0, #0xc]
    ldr r0, =0x7ff
    ldrh r3, [r2, #0x42]
    add ip, r2, #0x3c
    ldrh r2, [ip, r3]
    add r3, ip, r3
    mla r1, r2, r1, r3
    ldr r1, [r1, #0x8]
    and r2, r1, r0
    and r1, r1, r0, lsl #0xb
    mov r0, r2, lsl #0x10
    mov r1, r1, lsl #0x5
    mov r2, r0, lsr #0x10
    mov r0, r1, lsr #0x10
    mul r0, r2, r0
    bx lr
}
// clang-format on
