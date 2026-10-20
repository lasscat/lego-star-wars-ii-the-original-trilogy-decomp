#include "m2c.h"

extern void func_0202cb44();
extern void func_02018278();
extern void func_0205e80c();
extern void func_02032b44();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202e794(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x28
    mov r4, r0
    add r0, r4, #0x5e0
    bl      func_0202cb44
    mov r1, #0xb4
    str r1, [sp, #0x0]
    mov r3, #0x14
    mov r2, r0
    str r3, [sp, #0x4]
    mov ip, #0x32
    add r0, sp, #0x1c
    mov r1, r4
    mov r3, #0xaa
    str ip, [sp, #0x8]
    bl      func_02018278
    mov r0, #0x40
    mov r1, #0x1
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    addeq sp, sp, #0x28
    ldmeqia   sp!, {r4, pc}
    mov r1, #0x1
    str r1, [sp, #0x0]
    mov r2, #0x0
    mov ip, #0x1000
    rsb ip, ip, #0x0
    mov r3, #0x2000
    str r2, [sp, #0x4]
    mov r1, #0x6
    str r1, [sp, #0x8]
    str r2, [sp, #0xc]
    add r2, sp, #0x1c
    mov r1, r4
    str ip, [sp, #0x18]
    str r3, [sp, #0x14]
    str ip, [sp, #0x10]
    bl      func_02032b44
    add sp, sp, #0x28
    ldmia   sp!, {r4, pc}
}
// clang-format on
