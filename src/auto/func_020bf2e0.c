#include "m2c.h"

extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bf2e0(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0xc
    ldr r0, [r0, #0x14]
    ldr r6, [r1, #0x58]
    rsb r9, r0, #0x1000
    ldr r5, [r1, #0x5c]
    smull r0, r3, r6, r9
    smull r4, r2, r5, r9
    adds r4, r4, #0x800
    adc lr, r2, #0x0
    adds r8, r0, #0x800
    ldr r7, [r1, #0x54]
    mov     r4, r4, lsr 0xc
    smull r2, r0, r7, r9
    adc r3, r3, #0x0
    adds r2, r2, #0x800
    mov     ip, r8, lsr 0xc
    adc r8, r0, #0x0
    mov     r2, r2, lsr 0xc
    ldr r0, [sp, #0x30]
    orr r4, r4, lr, lsl #0x14
    orr ip, ip, r3, lsl #0x14
    orr r2, r2, r8, lsl #0x14
    smull r3, r8, r4, r0
    adds r9, r3, #0x800
    smull r3, lr, ip, r0
    adc r4, r8, #0x0
    adds ip, r3, #0x800
    mov     r3, r9, lsr 0xc
    orr r3, r3, r4, lsl #0x14
    sub r3, r5, r3
    smull r4, r0, r2, r0
    adc r5, lr, #0x0
    adds r2, r4, #0x800
    mov     r4, ip, lsr 0xc
    orr r4, r4, r5, lsl #0x14
    sub r4, r6, r4
    adc r0, r0, #0x0
    mov     r2, r2, lsr 0xc
    orr r2, r2, r0, lsl #0x14
    sub r5, r7, r2
    add r0, sp, #0x0
    add r2, r1, #0x54
    str r5, [sp, #0x0]
    str r4, [sp, #0x4]
    str r3, [sp, #0x8]
    cmp r2, r0
    addeq sp, sp, #0xc
    ldmeqfd   sp!, {r4, r5, r6, r7, r8, r9, lr}
    addeq sp, sp, #0x10
    bxeq lr
    str r5, [r1, #0x54]
    ldr r0, [sp, #0x4]
    str r0, [r1, #0x58]
    ldr r0, [sp, #0x8]
    str r0, [r1, #0x5c]
    add sp, sp, #0xc
    ldmfd   sp!, {r4, r5, r6, r7, r8, r9, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
