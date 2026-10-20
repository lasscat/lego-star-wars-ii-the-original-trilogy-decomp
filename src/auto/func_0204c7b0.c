#include "m2c.h"

extern void func_0204cb34(s32, s32, s32);

// clang-format off
asm void func_0204c7b0(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x30
    mov r4, r1
    ldr r1, [r4, #0x4]
    mov r5, r0
    cmp r1, #0x40000000
    blt L_0204c818
    ldr r0, [r4, #0x4]
    mov r0, r0, lsl #0x1d
    movs r0, r0, lsr #0x1f
    mov r0, #0x0
    str r0, [sp, #0x24]
    movne r1, #0x1
    mvneq r1, #0x0
    mov r3, r1, lsl #0xc
    str r0, [sp, #0x28]
    str r0, [sp, #0x2c]
    ldr r0, [r4, #0x4]
    add r1, sp, #0x24
    mov r2, r0, lsl #0x1e
    add r0, sp, #0x18
    mov r2, r2, lsr #0x1e
    str r3, [sp, #0x4]
    bl func_0204cb34
    add r2, sp, #0x18
    b L_0204c834
L_0204c818:
    ldrsh r0, [r4, #0x4]
    add r2, sp, #0xc
    str r0, [sp, #0xc]
    ldrsh r0, [r4, #0x6]
    str r0, [sp, #0x10]
    ldrsh r0, [r4, #0x8]
    str r0, [sp, #0x14]
L_0204c834:
    ldr r1, [r4, #0x0]
    str r1, [r5, #0x0]
    ldr r0, [r2, #0x0]
    str r1, [sp, #0x8]
    str r0, [r5, #0x4]
    ldr r0, [r2, #0x4]
    str r1, [sp, #0x0]
    str r0, [r5, #0x8]
    ldr r0, [r2, #0x8]
    str r0, [r5, #0xc]
    add sp, sp, #0x30
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
