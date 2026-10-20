#include "m2c.h"

extern u32 data_020fe6d0[];
extern u32 data_020fea10[];
extern void func_020534e0();
extern void func_0206d4d0();
extern void func_0206549c();
extern void func_020730d0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206f354(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    ldr     ip, =data_020fe6d0
    mov r4, r0
    str ip, [r4, #0x0]
    stmib r4, {r1, r2, r3}
    ldr r0, [sp, #0x10]
    ldr     r1, =data_020fea10
    str r0, [r4, #0x10]
    mov r0, #0x0
    str r0, [r4, #0x14]
    str r0, [r4, #0x18]
    str r0, [r4, #0x1c]
    str r0, [r4, #0x20]
    str r0, [r4, #0x24]
    add r0, r4, #0x28
    str r1, [r4, #0x0]
    bl      func_020534e0
    mov ip, #0x3
    add r0, r4, #0x30
    mov r1, #0x1
    mov r2, #0x4
    mov r3, #0x2
    str ip, [sp, #0x0]
    bl      func_0206d4d0
    add r0, r4, #0x5c
    bl      func_0206549c
    mov r2, #0x1
    ldr r1, [sp, #0x10]
    str r2, [r4, #0x98]
    mov r0, #0x2
    str r0, [r4, #0x9c]
    cmp r1, #0x0
    str r2, [r4, #0xa0]
    bne      L_0206f3e8
    bl      func_020730d0
    b      L_0206f3f0
    L_0206f3e8:
    mov r0, #0x4
    bl      func_020730d0
    L_0206f3f0:
    mov r0, r4
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
