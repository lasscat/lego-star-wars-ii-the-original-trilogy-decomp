#include "m2c.h"

extern u32 data_020e5d09[];
extern void func_020bc4cc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020186ec(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    ldr ip, [r0, #0x0]
    ldr lr, [r1, #0x0]
    ldr r2, [ip, #0x24]
    cmp r2, lr
    ldreq r3, [ip, #0x28]
    ldreq r2, [r1, #0x4]
    cmpeq r3, r2
    ldreq r3, [ip, #0x2c]
    ldreq r2, [r1, #0x8]
    cmpeq r3, r2
    movne r2, #0x1
    moveq r2, #0x0
    cmp r2, #0x0
    beq      L_02018754
    add r2, ip, #0x24
    cmp r2, r1
    beq      L_0201874c
    str lr, [ip, #0x24]
    ldr r2, [r1, #0x4]
    str r2, [ip, #0x28]
    ldr r1, [r1, #0x8]
    str r1, [ip, #0x2c]
    L_0201874c:
    mov r1, #0x1
    strb r1, [ip, #0x45]
    L_02018754:
    ldr r3, [r0, #0x0]
    ldrh r1, [sp, #0x10]
    ldrh r2, [r3, #0x3e]
    ldr     ip, =data_020e5d09
    cmp r2, r1
    strneh r1, [r3, #0x3e]
    movne r1, #0x1
    strneb r1, [r3, #0x44]
    ldrb r2, [r0, #0x6]
    mov r1, #0x6
    smulbb r2, r2, r1
    ldrb r2, [ip, r2]
    cmp r2, #0x0
    beq      L_020187b4
    ldr r2, [r0, #0x0]
    mov r3, #0x1
    strb r3, [r2, #0x39c]
    ldrb r2, [r0, #0x6]
    mul r1, r2, r1
    ldrb r1, [ip, r1]
    strb r1, [r0, #0x7]
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
    L_020187b4:
    ldr r0, [r0, #0x0]
    mov r1, #0x1
    bl      func_020bc4cc
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
