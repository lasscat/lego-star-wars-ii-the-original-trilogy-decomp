#include "m2c.h"

extern void func_020536ec();
extern void func_0205375c();
extern void func_02053850();
extern void func_02053888();
extern void func_02053808();
extern void func_020538c0();
extern void func_020531d8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020535a8(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x20
    mov r2, #0x0
    add r1, sp, #0x18
    mov r4, r0
    str r2, [sp, #0x18]
    str r2, [sp, #0x1c]
    bl      func_020536ec
    mov r2, #0x0
    add r1, sp, #0x10
    mov r0, r4
    str r2, [sp, #0x10]
    str r2, [sp, #0x14]
    bl      func_0205375c
    mov r2, #0x0
    sub r0, sp, #0x4
    strh r2, [r0, #0x0]
    ldr r1, [r0, #0x0]
    mov r0, r4
    strh r2, [sp, #0x0]
    bl      func_02053850
    mov r1, #0x1000
    mov r0, r4
    str r1, [sp, #0xc]
    bl      func_02053888
    mov r2, #0x0
    add r1, sp, #0x4
    mov r0, r4
    str r2, [sp, #0x4]
    str r2, [sp, #0x8]
    bl      func_02053808
    mov r0, r4
    mov r1, #0x0
    bl      func_020538c0
    mov r0, r4
    bl      func_020531d8
    mov r1, #0x0
    str r1, [r0, #0x4]
    mov r0, r4
    bl      func_020531d8
    ldr r1, [r0, #0x34]
    orr r1, r1, #0x1
    str r1, [r0, #0x34]
    add sp, sp, #0x20
    ldmia   sp!, {r4, pc}
}
// clang-format on
