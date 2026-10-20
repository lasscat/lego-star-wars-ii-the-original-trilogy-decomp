#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c0708(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0xc
    ldr r6, [r0, #0x14]
    ldr r3, [r1, #0x68]
    ldr r0, [r1, #0x64]
    smull ip, r4, r3, r6
    adds r5, ip, #0x800
    smull r3, lr, r0, r6
    adc ip, r4, #0x0
    mov     r0, r5, lsr 0xc
    adds r4, r3, #0x800
    ldr r2, [r1, #0x60]
    orr r0, r0, ip, lsl #0x14
    smull ip, r3, r2, r6
    adc r2, lr, #0x0
    adds ip, ip, #0x800
    mov     r4, r4, lsr 0xc
    orr r4, r4, r2, lsl #0x14
    adc r2, r3, #0x0
    mov     ip, ip, lsr 0xc
    orr ip, ip, r2, lsl #0x14
    add r2, sp, #0x0
    add r3, r1, #0x60
    str ip, [sp, #0x0]
    str r4, [sp, #0x4]
    str r0, [sp, #0x8]
    cmp r3, r2
    addeq sp, sp, #0xc
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    str ip, [r1, #0x60]
    ldr r0, [sp, #0x4]
    str r0, [r1, #0x64]
    ldr r0, [sp, #0x8]
    str r0, [r1, #0x68]
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
