#include "m2c.h"

extern void func_020140f8();
extern void func_02012744();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201da30(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x1bc]
    cmp r1, #0x3
    addls pc, pc, r1, lsl #0x2
    b      L_0201daa0
    L_0201da4c:
    b      L_0201daa0
    b      L_0201da5c
    b      L_0201da74
    b      L_0201da94
    L_0201da5c:
    mov r1, #0x1
    strb r1, [r4, #0x216]
    bl      func_020140f8
    mov r0, #0x3
    strb r0, [r4, #0x1bc]
    b      L_0201daa0
    L_0201da74:
    add r0, r4, #0x100
    ldrh r0, [r0, #0x4e]
    mov r0, r0, lsl #0x1e
    mov r0, r0, lsr #0x1f
    cmp r0, #0x1
    moveq r0, #0x3
    streqb r0, [r4, #0x1bc]
    b      L_0201daa0
    L_0201da94:
    ldr r0, [r4, #0x8]
    orr r0, r0, #0x2
    str r0, [r4, #0x8]
    L_0201daa0:
    add r1, sp, #0xc
    ldr r1, [r1, #0x0]
    mov r0, r4
    bl      func_02012744
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
