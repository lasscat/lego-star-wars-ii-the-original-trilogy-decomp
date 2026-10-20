#include "m2c.h"

extern void func_02075784();
extern void memset();
extern void func_02075850();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02075698(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r3, [r5, #0x8]
    mov r4, r1
    cmp r4, r3
    ldrls r1, [r5, #0x4]
    subls r0, r3, r4
    cmpls r1, r0
    bls      L_020756dc
    ldr r0, [r5, #0x4]
    mov r2, #0x0
    add r1, r0, r4
    mov r0, r5
    sub r1, r1, r3
    strb r2, [sp, #0x0]
    bl      func_02075784
    b      L_02075700
    L_020756dc:
    ldr r0, [r5, #0x0]
    mov r2, r4, lsl #0x2
    add r0, r0, r1, lsl #0x2
    mov r1, #0x0
    bl      memset
    ldr r0, [r5, #0x4]
    add r0, r0, r4
    str r0, [r5, #0x4]
    ldmia   sp!, {r3, r4, r5, pc}
    L_02075700:
    mov r0, r5
    mov r1, r4
    bl      func_02075850
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
