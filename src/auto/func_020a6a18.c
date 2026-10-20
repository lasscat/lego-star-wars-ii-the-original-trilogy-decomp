#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020a6a18(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr r0, [sp, #0x10]
    ldr r5, [r3, #0x0]
    ldr ip, [r0, #0x0]
    ldr r4, [r2, #0x0]
    smull lr, r5, ip, r5
    adds ip, lr, #0x800
    adc r5, r5, #0x0
    mov     ip, ip, lsr 0xc
    orr ip, ip, r5, lsl #0x14
    add r4, r4, ip
    str r4, [r1, #0x0]
    ldr r4, [r0, #0x0]
    ldr lr, [r3, #0x4]
    ldr ip, [r2, #0x4]
    smull r5, lr, r4, lr
    adds r5, r5, #0x800
    adc r4, lr, #0x0
    mov     r5, r5, lsr 0xc
    orr r5, r5, r4, lsl #0x14
    add ip, ip, r5
    str ip, [r1, #0x4]
    ldr ip, [r0, #0x0]
    ldr r3, [r3, #0x8]
    ldr r0, [r2, #0x8]
    smull r3, r2, ip, r3
    adds r3, r3, #0x800
    adc r2, r2, #0x0
    mov     r3, r3, lsr 0xc
    orr r3, r3, r2, lsl #0x14
    add r0, r0, r3
    str r0, [r1, #0x8]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
