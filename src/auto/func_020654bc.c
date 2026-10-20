#include "m2c.h"

extern u32 data_021047fc[];
extern u32 data_020edc7c[];

extern void func_0205ab30(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020654bc(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    ldr r3, =data_021047fc
    mov r2, #0x1c
    mov r5, r0
    mov r0, #0x38
    mla r3, r5, r0, r3
    mul r2, r1, r2
    ldrh r0, [r3, r2]
    add r4, r3, r2
    bl func_0205ab30
    ldrh r1, [r4, #0x2]
    cmp r1, #0x0
    bne L_02065554
    str r0, [r4, #0x4]
    ldrh r2, [r0, #0x0]
    ldr r1, =data_020edc7c
    strh r2, [r4, #0xa]
    ldrh r2, [r0, #0x2]
    ldr r1, [r1, r5, lsl #0x3]
    strh r2, [r4, #0xc]
    ldrb r2, [r0, #0x4]
    strb r2, [r4, #0x8]
    strb r1, [r4, #0xe]
    ldrb r2, [r0, #0x7]
    ldrb r1, [r0, #0x6]
    add r1, r2, r1, lsl #0x8
    add r1, r0, r1
    str r1, [r4, #0x10]
    ldrb r2, [r0, #0xb]
    ldrb r1, [r0, #0xa]
    add r1, r2, r1, lsl #0x8
    add r1, r0, r1
    str r1, [r4, #0x14]
    ldrb r2, [r0, #0xf]
    ldrb r1, [r0, #0xe]
    add r1, r2, r1, lsl #0x8
    add r0, r0, r1
    str r0, [r4, #0x18]
L_02065554:
    ldrh r0, [r4, #0x2]
    add r0, r0, #0x1
    strh r0, [r4, #0x2]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
