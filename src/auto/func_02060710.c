#include "m2c.h"

extern u32 data_020f88c4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060710(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x8
    add r1, r0, #0xc00
    ldrh r4, [r1, #0x26]
    ldr     lr, =data_020f88c4
    ldr r3, [r0, #0x1c]
    mov     r2, r4, asr 0x4
    mov     r2, r2, lsl 0x1
    add r2, r2, #0x1
    mov     r2, r2, lsl 0x1
    ldrsh r2, [lr, r2]
    strh r4, [sp, #0x6]
    smull r4, r2, r3, r2
    adds r3, r4, #0x800
    adc r2, r2, #0x0
    mov     r3, r3, lsr 0xc
    orr r3, r3, r2, lsl #0x14
    str r3, [r0, #0x18]
    ldrh ip, [r1, #0x26]
    ldrh r2, [r1, #0x28]
    ldr r5, [r0, #0x1c]
    mov     r3, ip, asr 0x4
    mov     r3, r3, lsl 0x2
    ldrsh r4, [lr, r3]
    mov     r3, r2, asr 0x4
    mov     r3, r3, lsl 0x2
    smull r4, r6, r5, r4
    adds r7, r4, #0x800
    ldrsh r4, [lr, r3]
    adc r5, r6, #0x0
    mov     r3, r7, lsr 0xc
    orr r3, r3, r5, lsl #0x14
    smull r5, r4, r3, r4
    adds r5, r5, #0x800
    adc r4, r4, #0x0
    mov     r5, r5, lsr 0xc
    ldr r6, [r0, #0x8]
    orr r5, r5, r4, lsl #0x14
    add r4, r6, r5
    str r4, [r0, #0x10]
    ldrh r4, [r1, #0x28]
    strh ip, [sp, #0x4]
    strh r2, [sp, #0x2]
    mov     ip, r4, asr 0x4
    mov     ip, ip, lsl 0x1
    add ip, ip, #0x1
    mov     ip, ip, lsl 0x1
    ldrsh ip, [lr, ip]
    ldr r1, [r0, #0xc]
    strh r4, [sp, #0x0]
    smull ip, r2, r3, ip
    adds r3, ip, #0x800
    adc r2, r2, #0x0
    mov     r3, r3, lsr 0xc
    orr r3, r3, r2, lsl #0x14
    add r1, r1, r3
    str r1, [r0, #0x14]
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
