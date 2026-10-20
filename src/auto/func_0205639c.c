#include "m2c.h"

extern void func_02067080();
extern u32 data_0210930c[];
extern void func_020906ec();
extern void func_02062a7c();
extern void func_020906a8();
extern void func_02098440();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205639c(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x10
    mov r5, r1
    ldrb r1, [r5, #0x0]
    ldrb r2, [r5, #0x1]
    bl      func_02067080
    movs r4, r0
    addeq sp, sp, #0x10
    ldmeqia   sp!, {r4, r5, r6, pc}
    ldrb r6, [r5, #0x2]
    ldr     r0, =data_0210930c
    ldr r0, [r0, #0x68]
    mov r1, r6
    bl      func_020906ec
    mov r1, r0
    mov r0, #0x0
    bl      func_02062a7c
    ldr     r1, =data_0210930c
    mov r3, r0
    ldr r1, [r1, #0x68]
    add r0, sp, #0x4
    mov r2, r6
    bl      func_020906a8
    ldr r0, [sp, #0x4]
    ldr r1, [r4, #0xb0]
    mov r2, r0
    cmp r1, r0
    ldreq r1, [r4, #0xb4]
    ldreq r0, [sp, #0x8]
    cmpeq r1, r0
    ldreq r1, [r4, #0xb8]
    ldreq r0, [sp, #0xc]
    cmpeq r1, r0
    movne r0, #0x1
    moveq r0, #0x0
    cmp r0, #0x0
    beq      L_0205645c
    add r0, sp, #0x4
    add r1, r4, #0xb0
    cmp r1, r0
    beq      L_02056454
    str r2, [r4, #0xb0]
    ldr r0, [sp, #0x8]
    str r0, [r4, #0xb4]
    ldr r0, [sp, #0xc]
    str r0, [r4, #0xb8]
    L_02056454:
    mov r0, #0x1
    strb r0, [r4, #0xd1]
    L_0205645c:
    ldrb r1, [r5, #0x3]
    add r0, sp, #0x2
    bl      func_02098440
    ldrh r1, [sp, #0x2]
    ldrh r0, [r4, #0xca]
    strh r1, [sp, #0x0]
    cmp r0, r1
    strneh r1, [r4, #0xca]
    movne r0, #0x1
    strneb r0, [r4, #0xd0]
    add sp, sp, #0x10
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
