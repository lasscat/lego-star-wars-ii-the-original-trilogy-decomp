#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204d638(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr r5, [r0, #0x28]
    ldr r4, [r0, #0x8]
    ldr r2, [r1, #0x4]
    add r3, r4, r5
    cmp r3, r2
    sub r3, r4, r5
    movlt r0, #0x0
    ldmltia   sp!, {r3, r4, r5, pc}
    cmp r3, r2
    movgt r0, #0x0
    ldmgtia   sp!, {r3, r4, r5, pc}
    ldr r4, [r1, #0x0]
    ldr r2, [r0, #0x4]
    ldr r5, [r0, #0x2c]
    ldr r3, [r1, #0x8]
    ldr r0, [r0, #0xc]
    sub r1, r4, r2
    sub ip, r3, r0
    smull r0, r2, r1, r1
    adds r4, r0, #0x800
    mov r0, #0x0
    smull r1, r3, ip, ip
    adc lr, r2, r0
    adds ip, r1, #0x800
    mov     r4, r4, lsr 0xc
    smull r2, r1, r5, r5
    adc r3, r3, r0
    adds r2, r2, #0x800
    mov     ip, ip, lsr 0xc
    orr r4, r4, lr, lsl #0x14
    orr ip, ip, r3, lsl #0x14
    adc r1, r1, r0
    mov     r2, r2, lsr 0xc
    add r3, r4, ip
    orr r2, r2, r1, lsl #0x14
    cmp r3, r2
    movle r0, #0x1
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
