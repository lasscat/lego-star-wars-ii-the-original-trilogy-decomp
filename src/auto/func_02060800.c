#include "m2c.h"

extern u32 data_020f88c4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060800(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x8
    add r1, r0, #0xc00
    ldrh lr, [r1, #0x26]
    ldrh r2, [r1, #0x28]
    ldr     r3, =data_020f88c4
    mov     r4, lr, asr 0x4
    mov     r4, r4, lsl 0x2
    ldrsh r4, [r3, r4]
    ldr r5, [r0, #0x1c]
    strh lr, [sp, #0x4]
    smull r4, r6, r5, r4
    adds ip, r4, #0x800
    mov     r4, r2, asr 0x4
    mov     r4, r4, lsl 0x2
    adc r5, r6, #0x0
    mov     ip, ip, lsr 0xc
    ldrsh r4, [r3, r4]
    orr ip, ip, r5, lsl #0x14
    ldr r6, [r0, #0x10]
    smull r5, r4, ip, r4
    adds r5, r5, #0x800
    adc r4, r4, #0x0
    mov     r5, r5, lsr 0xc
    orr r5, r5, r4, lsl #0x14
    sub r4, r6, r5
    str r4, [r0, #0x8]
    ldrh r4, [r1, #0x28]
    strh r2, [sp, #0x2]
    ldr r1, [r0, #0x14]
    mov     lr, r4, asr 0x4
    mov     lr, lr, lsl 0x1
    add lr, lr, #0x1
    mov     lr, lr, lsl 0x1
    ldrsh r3, [r3, lr]
    strh r4, [sp, #0x0]
    smull r3, r2, ip, r3
    adds r3, r3, #0x800
    adc r2, r2, #0x0
    mov     r3, r3, lsr 0xc
    orr r3, r3, r2, lsl #0x14
    sub r1, r1, r3
    str r1, [r0, #0xc]
    add sp, sp, #0x8
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
