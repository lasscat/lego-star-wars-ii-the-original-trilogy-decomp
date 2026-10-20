#include "m2c.h"

extern u32 data_020edef2[];
extern void func_02053c2c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207094c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x8
    mov r8, r1
    cmp r8, #0x4
    mov r9, r0
    addge sp, sp, #0x8
    ldmgeia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr     r5, =data_020edef2
    mov r7, #0x3
    mov r6, #0x0
    mov r4, #0x18
    L_02070978:
    str r7, [sp, #0x0]
    str r6, [sp, #0x4]
    mov r1, r8, lsl #0x2
    add r0, r5, r8, lsl #0x2
    ldrsh r1, [r5, r1]
    ldrsh r0, [r0, #0x2]
    mov r3, r4
    sub r1, r1, #0x5
    sub ip, r0, #0x5
    mov r0, r1, asr #0x2
    mov r2, ip, asr #0x2
    add r1, r1, r0, lsr #0x1d
    add r2, ip, r2, lsr #0x1d
    add r0, r9, #0x28
    mov r1, r1, asr #0x3
    mov r2, r2, asr #0x3
    bl      func_02053c2c
    add r8, r8, #0x1
    cmp r8, #0x4
    blt      L_02070978
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
