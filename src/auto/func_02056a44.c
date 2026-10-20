#include "m2c.h"

extern void func_02067080();
extern void func_0205e80c();
extern void func_020941bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02056a44(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r1
    ldrb r1, [r4, #0x0]
    ldrb r2, [r4, #0x1]
    bl      func_02067080
    movs r5, r0
    ldmeqia   sp!, {r3, r4, r5, pc}
    ldrb r0, [r4, #0x3]
    mov r3, #0x1
    cmp r0, #0x0
    ldrb r0, [r4, #0x4]
    movne r2, #0x1
    moveq r2, #0x0
    cmp r0, #0x0
    movne r0, #0x1
    moveq r0, #0x0
    str r0, [sp, #0x0]
    mov r0, r5
    ldr ip, [r0, #0x0]
    ldrb r1, [r4, #0x2]
    ldr ip, [ip, #0x24]
    blx      ip
    ldrb r0, [r4, #0x5]
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r0, #0x10
    mov r1, #0x0
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r1, #0x1
    str r1, [sp, #0x0]
    ldrb r3, [r4, #0x5]
    mov r1, r5
    mov r2, #0x0
    bl      func_020941bc
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
