#include "m2c.h"

extern u32 data_020f88c4[];
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02028fb0(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    ldrh r2, [sp, #0x20]
    ldr r3, [r1, #0x0]
    str r3, [r0, #0x0]
    ldr r3, [r1, #0x4]
    mov     r2, r2, asr 0x4
    mov     r4, r2, lsl 0x1
    str r3, [r0, #0x4]
    ldr r3, [r1, #0x8]
    add r1, r4, #0x1
    ldr     r2, =data_020f88c4
    mov     r4, r4, lsl 0x1
    mov     r1, r1, lsl 0x1
    str r3, [r0, #0x8]
    ldrsh r7, [r2, r4]
    ldrsh r8, [r2, r1]
    ldr r6, [r0, #0x0]
    smull r2, r1, r3, r7
    adds r4, r2, #0x800
    smull r2, r5, r6, r8
    adc r1, r1, #0x0
    adds lr, r2, #0x800
    mov     r2, r4, lsr 0xc
    smull ip, r4, r6, r7
    adc r6, r5, #0x0
    adds r5, ip, #0x800
    mov     r7, lr, lsr 0xc
    smull lr, ip, r3, r8
    adc r4, r4, #0x0
    mov     r5, r5, lsr 0xc
    adds r3, lr, #0x800
    orr r2, r2, r1, lsl #0x14
    orr r7, r7, r6, lsl #0x14
    add lr, r7, r2
    adc r1, ip, #0x0
    mov     r2, r3, lsr 0xc
    orr r5, r5, r4, lsl #0x14
    orr r2, r2, r1, lsl #0x14
    str lr, [r0, #0x0]
    sub r1, r2, r5
    str r1, [r0, #0x8]
    ldmfd   sp!, {r4, r5, r6, r7, r8, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
