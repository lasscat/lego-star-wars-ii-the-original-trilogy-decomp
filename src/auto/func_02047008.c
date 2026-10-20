#include "m2c.h"

extern s32 func_02007f24(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02047008(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    cmp r1, #0x0
    mov r4, r0
    addeq sp, sp, #0xc
    ldmeqia sp!, {r3, r4, pc}
    mov r0, #0x0
    strb r0, [r4, #0x1b]
    ldrb r0, [r4, #0x16]
    cmp r0, #0xe
    cmpne r0, #0x8
    bne L_0204709c
    ldr r3, [r4, #0x4]
    mov ip, #0x0
    ldr r1, =0x66666666
    ldr r2, =0x3ff66666
    add r0, sp, #0x4
    strb ip, [r3, #0x40]
    bl func_02007f24
    ldr r1, =0xcccccccd
    ldr r2, =0x3ff8cccc
    add r0, sp, #0x8
    bl func_02007f24
    add r0, sp, #0x8
    ldr r1, [sp, #0x4]
    ldr r2, [r0, #0x0]
    ldr r0, [r4, #0x4]
    smull r3, r1, r2, r1
    adds r2, r3, #0x800
    adc r1, r1, #0x0
    mov r2, r2, lsr #0xc
    orr r2, r2, r1, lsl #0x14
    str r2, [r0, #0x64]
    mov r0, #0x1
    add sp, sp, #0xc
    strb r0, [r4, #0xd]
    ldmia sp!, {r3, r4, pc}
L_0204709c:
    ldr r1, =0xcccccccd
    ldr r2, =0x3ff8cccc
    add r0, sp, #0x0
    bl func_02007f24
    ldr r1, [sp, #0x0]
    ldr r0, [r4, #0x4]
    str r1, [r0, #0x64]
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
