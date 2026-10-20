#include "m2c.h"

extern void func_02067080();
extern void func_0202d934();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020581fc(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x14
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
    cmp r4, #0x0
    cmpne r0, #0x0
    addeq sp, sp, #0x14
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    ldr r1, [r0, #0xb0]
    mov ip, #0x1000
    str r1, [sp, #0x8]
    ldr r1, [r0, #0xb4]
    rsb ip, ip, #0x0
    str r1, [sp, #0xc]
    ldr r0, [r0, #0xb8]
    add r1, sp, #0x8
    str r0, [sp, #0x10]
    str ip, [sp, #0x0]
    ldrb r2, [r5, #0x4]
    ldrb r3, [r5, #0x5]
    mov r0, r4
    str ip, [sp, #0x4]
    bl      func_0202d934
    add sp, sp, #0x14
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
