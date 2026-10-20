#include "m2c.h"

extern u32 data_0210b348[];
extern void func_0206574c();
extern void func_02065600();
extern void func_02066708();
extern void func_02065be8();
extern void func_02072900();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206f748(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x8
    ldr     r1, =data_0210b348
    mov r5, r0
    ldr r0, [r1, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x3c]
    blx      r1
    mov r1, #0x6
    add r0, r5, #0x5c
    sub r2, r1, #0x8
    bl      func_0206574c
    add r0, r5, #0x5c
    mov r1, #0x4
    bl      func_02065600
    mov r0, #0x66
    bl      func_02066708
    str r0, [sp, #0x0]
    mov r1, #0x1
    str r1, [sp, #0x4]
    add r0, r5, #0x5c
    mov r2, #0x7f
    mov r3, #0xc
    bl      func_02065be8
    mov r4, r0
    add r0, r5, #0x5c
    mov r1, #0x0
    sub r2, r1, #0x2
    bl      func_0206574c
    str r4, [r5, #0xa0]
    mov r0, #0x69
    bl      func_02066708
    mov r1, r4
    str r0, [sp, #0x0]
    mov r0, #0x1
    str r0, [sp, #0x4]
    add r0, r5, #0x5c
    mov r2, #0x56
    mov r3, #0x98
    bl      func_02065be8
    mov r4, r0
    mov r0, #0x8a
    bl      func_02066708
    mov r1, r4
    str r0, [sp, #0x0]
    mov r0, #0x1
    str r0, [sp, #0x4]
    add r0, r5, #0x5c
    mov r2, #0xaa
    mov r3, #0x98
    bl      func_02065be8
    str r0, [r5, #0x98]
    add r0, r5, #0x5c
    mov r1, #0x3
    bl      func_02065600
    add r0, r5, #0x5c
    mov r1, #0x9
    sub r2, r1, #0xb
    bl      func_0206574c
    mov r0, #0x28c
    bl      func_02072900
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
