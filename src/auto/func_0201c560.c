#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201c560(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, lr}
    ldr r3, [r1, #0x4c]
    ldr ip, [sp, #0x10]
    ldr r2, [sp, #0x14]
    ldr r1, [r1, #0x50]
    sub ip, ip, r3
    sub lr, r2, r1
    smull r1, r3, ip, ip
    adds ip, r1, #0x800
    smull r2, r1, lr, lr
    adc r3, r3, #0x0
    adds r2, r2, #0x800
    mov ip, ip, lsr #0xc
    adc r1, r1, #0x0
    mov r2, r2, lsr #0xc
    orr ip, ip, r3, lsl #0x14
    orr r2, r2, r1, lsl #0x14
    ldr r0, [r0, #0x8]
    add r1, ip, r2
    cmp r1, r0
    mov r0, #0x0
    movle r0, #0x1
    ldmfd sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
