#include "m2c.h"

extern void func_01ffa408();
extern void func_0205c274();
extern void func_0205c0f0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205c8d4(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r1
    mov r8, r0
    mov r0, r7
    mov r6, r2
    mov r5, r3
    bl      func_01ffa408
    mov r4, r0
    mov r0, r7
    bl      func_01ffa408
    mov r1, r4
    mov r2, r0
    ldr r0, [r8, r6, lsl #0x2]
    bl      func_0205c274
    ldr r0, [r8, r6, lsl #0x2]
    mov r1, r7
    mov r2, r5
    bl      func_0205c0f0
    mov r0, #0x1
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
