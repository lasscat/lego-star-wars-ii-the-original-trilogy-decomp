#include "m2c.h"

extern void func_02067080();
extern void func_0202d9ac();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02058280(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4
    mov r5, r1
    ldrb r1, [r5, #0x0]
    ldrb r2, [r5, #0x1]
    mov r6, r0
    bl      func_02067080
    mov r4, r0
    ldrb r1, [r5, #0x2]
    ldrb r2, [r5, #0x3]
    mov r0, r6
    bl      func_02067080
    mov r1, r0
    cmp r4, #0x0
    cmpne r1, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    ldrb r2, [r5, #0x4]
    mov r0, r4
    mov     r2, r2, lsl 0xc
    str r2, [sp, #0x0]
    bl      func_0202d9ac
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
