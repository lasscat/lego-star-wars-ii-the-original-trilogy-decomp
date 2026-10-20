#include "m2c.h"

extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207ef78(s32 a0) {
    ldr r1, [r0, #0x34]
    ldr r0, [r0, #0x30]
    ldr     r2, =0x6b5fca6b
    sub r0, r1, r0
    smull r1, ip, r2, r0
    mov     r3, r0, lsr 0x1f
    add ip, r3, ip, asr #0x16
    cmp ip, #0x0
    ldrgt     r0, =0xf4240
    bxgt lr
    ldr     r2, =0x431bde83
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0x12
    cmp ip, #0x0
    ldrgt     r0, =0x186a0
    bxgt lr
    ldr     r2, =0x14f8b589
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0xd
    cmp ip, #0x0
    ldrgt     r0, =0x2710
    bxgt lr
    ldr     r2, =0x68db8bad
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0xc
    cmp ip, #0x0
    movgt r0, #0x3e8
    bxgt lr
    ldr     r2, =0x10624dd3
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0x6
    cmp ip, #0x0
    movgt r0, #0x64
    bxgt lr
    ldr     r2, =0x51eb851f
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0x5
    cmp ip, #0x0
    movgt r0, #0xa
    bxgt lr
    ldr     r2, =0x66666667
    smull r1, ip, r2, r0
    add ip, r3, ip, asr #0x2
    cmp ip, #0x0
    movgt r0, #0xa
    bxgt lr
    cmp r0, #0x0
    movgt r0, #0x1
    movle r0, #0x0
    bx lr
}
// clang-format on
