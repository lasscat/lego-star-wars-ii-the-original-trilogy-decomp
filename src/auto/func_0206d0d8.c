#include "m2c.h"

extern u32 data_020fe870[];
extern u32 data_02102900[];
extern void func_020601f4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206d0d8(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r2, =data_020fe870
    mov r4, r0
    str r2, [r4, #0x0]
    ldr     r0, =data_02102900
    str r1, [r4, #0x4]
    mov r2, r1
    mov r1, r4
    bl      func_020601f4
    mov r0, r4
    ldmia   sp!, {r4, pc}
}
// clang-format on
