#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204d328(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    ldr r5, [r1, #0x0]
    ldr r3, [r0, #0x4]
    ldr r4, [r1, #0x4]
    ldr r2, [r0, #0x8]
    sub r3, r5, r3
    sub ip, r4, r2
    smull r2, r4, r3, r3
    ldr r3, [r0, #0x30]
    adds r6, r2, #0x800
    ldr r0, [r0, #0xc]
    ldr r1, [r1, #0x8]
    smull r2, r5, ip, ip
    sub r7, r1, r0
    mov r0, #0x0
    adc r1, r4, r0
    adds lr, r2, #0x800
    mov     r2, r6, lsr 0xc
    smull ip, r4, r7, r7
    adc r6, r5, r0
    adds r5, ip, #0x800
    mov     r7, lr, lsr 0xc
    smull lr, ip, r3, r3
    adc r4, r4, r0
    mov     r5, r5, lsr 0xc
    adds r3, lr, #0x800
    orr r2, r2, r1, lsl #0x14
    orr r7, r7, r6, lsl #0x14
    add r6, r2, r7
    orr r5, r5, r4, lsl #0x14
    mov     r2, r3, lsr 0xc
    adc r1, ip, r0
    add r3, r6, r5
    orr r2, r2, r1, lsl #0x14
    cmp r3, r2
    movle r0, #0x1
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
