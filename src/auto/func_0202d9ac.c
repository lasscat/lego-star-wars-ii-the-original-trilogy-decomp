#include "m2c.h"

extern void func_0205e80c();
extern void func_02031f24();
extern void func_0202c1a8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202d9ac(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x10
    mov r6, r0
    mov r5, r1
    mov r0, #0x24
    mov r1, #0x1
    mov r2, #0x4
    bl      func_0205e80c
    movs r4, r0
    beq      L_0202da0c
    mov r2, #0x0
    add r1, sp, #0x28
    ldr r3, [r1, #0x0]
    strh r2, [sp, #0xc]
    mov ip, r2
    str r2, [sp, #0x0]
    mov r2, #0x1
    str r2, [sp, #0x4]
    mov r1, r6
    mov r2, r5
    strh ip, [sp, #0x8]
    bl      func_02031f24
    mov r4, r0
    L_0202da0c:
    mov r1, r4
    add r0, r6, #0x5e0
    bl      func_0202c1a8
    mov r0, r4
    add sp, sp, #0x10
    ldmfd   sp!, {r4, r5, r6, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
