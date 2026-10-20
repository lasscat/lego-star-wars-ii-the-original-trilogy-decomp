#include "m2c.h"

extern u32 data_0210930c[];
extern void func_0204f9bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202db94(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0xc
    mov r2, r0
    ldr r0, [r2, #0x4]
    mov r3, r1
    add r0, r0, #0x2000
    str r0, [r2, #0x4]
    ldr r0, [r3, #0x4]
    mov r1, #0x0
    add r0, r0, #0x2000
    str r0, [r3, #0x4]
    ldr     r0, =data_0210930c
    str r1, [sp, #0x0]
    ldr r1, [r0, #0x68]
    add r0, sp, #0x4
    ldr r1, [r1, #0x384]
    bl      func_0204f9bc
    ldr r0, [sp, #0x8]
    cmp r0, #0x2000
    movge r0, #0x1
    movlt r0, #0x0
    add sp, sp, #0xc
    ldmia   sp!, {pc}
}
// clang-format on
