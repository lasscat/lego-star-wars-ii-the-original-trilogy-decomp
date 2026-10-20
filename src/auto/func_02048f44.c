#include "m2c.h"

extern void func_0201811c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02048f44(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r6, [r0, #0x4]
    mov r7, #0x0
    ldr r0, [r6, #0x7fc]
    cmp r0, #0x0
    bls      L_02048fc8
    ldr     r9, =0x9c4000
    add r5, sp, #0x0
    mov r4, #0x1
    L_02048f68:
    add r1, r6, r7, lsl #0x3
    ldr r0, [r1, #0x6fc]
    ldr r8, [r1, #0x6f8]
    cmp r0, r9
    movgt r0, #0x0
    ldmgtia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r0, r5
    mov r1, r6
    mov r2, r8
    mov r3, r4
    bl      func_0201811c
    ldrh r0, [r8, #0xc]
    cmp r0, #0x2
    bne      L_02048fb8
    ldrsh r0, [sp, #0x0]
    cmp r0, #0x0
    rsblt r0, r0, #0x0
    cmp r0, #0x4000
    movlt r0, r8
    ldmltia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    L_02048fb8:
    ldr r0, [r6, #0x7fc]
    add r7, r7, #0x1
    cmp r7, r0
    blo      L_02048f68
    L_02048fc8:
    mov r0, #0x0
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
