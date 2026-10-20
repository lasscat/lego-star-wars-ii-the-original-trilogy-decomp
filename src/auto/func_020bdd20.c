#include "m2c.h"

extern void func_020bd884();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bdd20(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldr r2, [r4, #0x6c]
    ldr r1, [r4, #0x68]
    add r0, r4, #0x50
    sub r1, r2, r1
    mov r2, #0x1
    str r1, [sp, #0x4]
    bl      func_020bd884
    mov r1, #0x10000
    add r0, r4, #0x48
    mov r2, #0x0
    str r1, [sp, #0x0]
    bl      func_020bd884
    ldr r1, [r4, #0x70]
    add r0, r4, #0x58
    mov r2, #0x1
    bl      func_020bd884
    add sp, sp, #0x8
    ldmia   sp!, {r4, pc}
}
// clang-format on
