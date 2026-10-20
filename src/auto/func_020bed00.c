#include "m2c.h"

extern u32 data_0210e6f4[];
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bed00(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0xc
    ldr r2, [r1, #0x4c]
    mov r0, #0xc
    mul r3, r2, r0
    ldr     r4, =data_0210e6f4
    ldr lr, [sp, #0x28]
    add r0, r4, r3
    ldr r2, [r0, #0x8]
    ldr r3, [r4, r3]
    smull r4, r5, r2, lr
    ldr r0, [r0, #0x4]
    adds ip, r4, #0x800
    smull r2, r4, r0, lr
    adc r0, r5, #0x0
    adds r6, r2, #0x800
    mov     r2, ip, lsr 0xc
    smull lr, ip, r3, lr
    adc r5, r4, #0x0
    adds r3, lr, #0x800
    mov     r6, r6, lsr 0xc
    adc lr, ip, #0x0
    mov     r4, r3, lsr 0xc
    orr r2, r2, r0, lsl #0x14
    ldr ip, [r1, #0x5c]
    orr r4, r4, lr, lsl #0x14
    add lr, ip, r2
    ldr r3, [r1, #0x58]
    ldr r0, [r1, #0x54]
    orr r6, r6, r5, lsl #0x14
    add ip, r3, r6
    add r3, r0, r4
    add r0, sp, #0x0
    add r2, r1, #0x54
    str r3, [sp, #0x0]
    str ip, [sp, #0x4]
    str lr, [sp, #0x8]
    cmp r2, r0
    addeq sp, sp, #0xc
    ldmeqfd   sp!, {r3, r4, r5, r6, lr}
    addeq sp, sp, #0x10
    bxeq lr
    str r3, [r1, #0x54]
    ldr r0, [sp, #0x4]
    str r0, [r1, #0x58]
    ldr r0, [sp, #0x8]
    str r0, [r1, #0x5c]
    add sp, sp, #0xc
    ldmfd   sp!, {r3, r4, r5, r6, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
