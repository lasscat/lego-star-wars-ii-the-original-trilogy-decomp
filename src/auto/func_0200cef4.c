#include "m2c.h"

extern u32 data_02106d90[];
extern void func_0209d0e0();
extern void func_020b9584();
extern void func_0205e80c();
extern void func_020bbfe8();
extern void func_0205ab44();
extern void func_020bbeb0();
extern void func_0205ab58();
extern void func_020bbf78();
extern void func_020bc4cc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200cef4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #16
    mov r4, r0
    ldrb r0, [r4, #0x1c1]
    cmp r0, #0
    addne sp, sp, #16
    ldmneia sp!, {r4, r5, r6, pc}
    ldr     r0, =data_02106d90
    ldr r0, [r0, #0xad0]
    ldr r0, [r0, #0x10]
    cmp r0, #0
    ldrneb r1, [r4, #0x1c0]
    cmpne r1, #0
    beq    L_0200cf38
    ldr r1, [r4, #0x1bc]
    and r1, r1, #255
    bl     func_0209d0e0
L_0200cf38:
    mov r2, #0
    mov r0, r4
    str r2, [sp]
    ldr r5, [r0]
    mov r1, #53
    ldr r5, [r5, #0x24]
    mov r3, #1
    blx r5
    mov r0, #1
    strb r0, [r4, #0x1c1]
    mov r0, #2
    strb r0, [r4, #0x1c6]
    add r1, r4, #176
    mov r0, #67
    bl     func_020b9584
    ldr r6, [r4, #0xb0]
    ldr r5, [r4, #0xb4]
    ldr r3, [r4, #0xb8]
    mov r0, #928
    mov r1, #3
    mov r2, #4
    str r6, [sp, #4]
    str r5, [sp, #8]
    str r3, [sp, #0xc]
    bl     func_0205e80c
    movs r4, r0
    beq    L_0200cfac
    bl     func_020bbfe8
    mov r4, r0
L_0200cfac:
    mov r0, #928
    mov r1, #3
    mov r2, #4
    bl     func_0205e80c
    movs r5, r0
    beq    L_0200cfcc
    bl     func_020bbfe8
    mov r5, r0
L_0200cfcc:
    mov r0, #928
    mov r1, #3
    mov r2, #4
    bl     func_0205e80c
    movs r6, r0
    beq    L_0200cfec
    bl     func_020bbfe8
    mov r6, r0
L_0200cfec:
    ldr     r0, =0x8a4
    bl     func_0205ab44
    mov r1, r0
    mov r0, r4
    bl     func_020bbeb0
    ldr     r0, =0x8a8
    bl     func_0205ab58
    mov r2, r0
    ldr     r1, =0x8a8
    mov r0, r4
    mov r3, #0
    bl     func_020bbf78
    ldr     r0, =0x8b8
    bl     func_0205ab44
    mov r1, r0
    mov r0, r5
    bl     func_020bbeb0
    ldr     r0, =0x8a9
    bl     func_0205ab58
    mov r2, r0
    ldr     r1, =0x8a9
    mov r0, r5
    mov r3, #0
    bl     func_020bbf78
    ldr     r0, =0x8b5
    bl     func_0205ab44
    mov r1, r0
    mov r0, r6
    bl     func_020bbeb0
    ldr     r0, =0x8b3
    bl     func_0205ab58
    mov r2, r0
    ldr     r1, =0x8b3
    mov r0, r6
    mov r3, #0
    bl     func_020bbf78
    ldr r0, [sp, #4]
    ldr r2, [r4, #0x24]
    mov r1, r0
    cmp r2, r1
    ldreq r2, [r4, #0x28]
    ldreq r1, [sp, #8]
    cmpeq r2, r1
    ldreq r2, [r4, #0x2c]
    ldreq r1, [sp, #0xc]
    cmpeq r2, r1
    movne r1, #1
    moveq r1, #0
    cmp r1, #0
    beq    L_0200d0e0
    add r1, sp, #4
    add r2, r4, #36
    cmp r2, r1
    beq    L_0200d0d8
    ldr r1, [sp, #8]
    str r0, [r4, #0x24]
    ldr r0, [sp, #0xc]
    str r1, [r4, #0x28]
    str r0, [r4, #0x2c]
L_0200d0d8:
    mov r0, #1
    strb r0, [r4, #0x45]
L_0200d0e0:
    mov r0, r4
    mov r1, #1
    bl     func_020bc4cc
    ldr r1, [r4, #0x384]
    ldr r0, [sp, #4]
    orr r1, r1, #2147483648
    str r1, [r4, #0x384]
    ldr r1, [r5, #0x24]
    ldr r2, [sp, #4]
    cmp r1, r0
    ldreq r1, [r5, #0x28]
    ldreq r0, [sp, #8]
    cmpeq r1, r0
    ldreq r1, [r5, #0x2c]
    ldreq r0, [sp, #0xc]
    cmpeq r1, r0
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_0200d15c
    add r0, sp, #4
    add r1, r5, #36
    cmp r1, r0
    beq    L_0200d154
    ldr r1, [sp, #8]
    str r2, [r5, #0x24]
    ldr r0, [sp, #0xc]
    str r1, [r5, #0x28]
    str r0, [r5, #0x2c]
L_0200d154:
    mov r0, #1
    strb r0, [r5, #0x45]
L_0200d15c:
    mov r0, r5
    mov r1, #1
    bl     func_020bc4cc
    ldr r1, [r5, #0x384]
    ldr r0, [sp, #4]
    orr r1, r1, #2147483648
    str r1, [r5, #0x384]
    ldr r1, [r6, #0x24]
    ldr r2, [sp, #4]
    cmp r1, r0
    ldreq r1, [r6, #0x28]
    ldreq r0, [sp, #8]
    cmpeq r1, r0
    ldreq r1, [r6, #0x2c]
    ldreq r0, [sp, #0xc]
    cmpeq r1, r0
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_0200d1d8
    add r0, sp, #4
    add r1, r6, #36
    cmp r1, r0
    beq    L_0200d1d0
    ldr r1, [sp, #8]
    str r2, [r6, #0x24]
    ldr r0, [sp, #0xc]
    str r1, [r6, #0x28]
    str r0, [r6, #0x2c]
L_0200d1d0:
    mov r0, #1
    strb r0, [r6, #0x45]
L_0200d1d8:
    mov r0, r6
    mov r1, #1
    bl     func_020bc4cc
    ldr r0, [r6, #0x384]
    orr r0, r0, #2147483648
    str r0, [r6, #0x384]
    add sp, sp, #16
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
