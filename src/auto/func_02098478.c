#include "m2c.h"

extern s32 func_02062ae4(s32 a0, s32 a1);
extern u16 func_02062a7c(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02098478(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x10
    mov r1, r1, lsl #0x17
    mov r4, r0
    mov r0, #0x64
    mov r5, r1, lsr #0x10
    bl func_02062ae4
    cmp r0, #0x32
    mov r1, r5
    mov r0, #0x0
    bhs L_020984d4
    bl func_02062a7c
    strh r0, [sp, #0xe]
    ldrh r1, [sp, #0xe]
    ldrh r0, [r4, #0x0]
    strh r1, [sp, #0xa]
    add r0, r0, r1
    strh r0, [sp, #0x6]
    ldrh r0, [sp, #0x6]
    strh r0, [sp, #0x8]
    add sp, sp, #0x10
    strh r0, [r4, #0x0]
    ldmia sp!, {r3, r4, r5, pc}
L_020984d4:
    bl func_02062a7c
    strh r0, [sp, #0xc]
    ldrh r1, [sp, #0xc]
    ldrh r0, [r4, #0x0]
    strh r1, [sp, #0x4]
    sub r0, r0, r1
    strh r0, [sp, #0x0]
    ldrh r0, [sp, #0x0]
    strh r0, [sp, #0x2]
    strh r0, [r4, #0x0]
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
