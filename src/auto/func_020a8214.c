#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020a8214(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r5, [r3, #0x8]
    ldr lr, [r1, #0x8]
    ldr ip, [r2, #0x8]
    ldr r3, [r3, #0x0]
    ldr r0, [r1, #0x0]
    ldr r2, [r2, #0x0]
    sub r4, r5, lr
    sub lr, r3, r2
    sub r2, r5, ip
    sub r1, r3, r0
    smull r0, r3, r1, r2
    adds ip, r0, #0x800
    mov r0, #0x0
    smull r2, r1, lr, r4
    adc r3, r3, r0
    adds r2, r2, #0x800
    mov ip, ip, lsr #0xc
    adc r1, r1, r0
    mov r2, r2, lsr #0xc
    orr ip, ip, r3, lsl #0x14
    orr r2, r2, r1, lsl #0x14
    sub r1, ip, r2
    cmp r1, #0x0
    movgt r0, #0x1
    ldmfd sp!, {r3, r4, r5, pc}
}
// clang-format on
