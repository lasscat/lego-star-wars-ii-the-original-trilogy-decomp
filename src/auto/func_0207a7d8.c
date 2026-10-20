#include "m2c.h"

extern void func_0201c1e4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207a7d8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r2, =0x6b5fca6b
    mov r4, r0
    umull r0, r2, r1, r2
    mov r0, #0x0
    movs r2, r2, lsr #0x16
    movne r0, #0x9
    bne      L_0207a880
    ldr     r2, =0x431bde83
    umull r2, r3, r1, r2
    movs r3, r3, lsr #0x12
    movne r0, #0x8
    bne      L_0207a880
    ldr     r2, =0x4f8b588f
    umull r2, r3, r1, r2
    sub r2, r1, r3
    add r3, r3, r2, lsr #0x1
    movs r3, r3, lsr #0x10
    movne r0, #0x7
    bne      L_0207a880
    ldr     r2, =0xd1b71759
    umull r2, r3, r1, r2
    movs r3, r3, lsr #0xd
    movne r0, #0x6
    bne      L_0207a880
    ldr     r2, =0x10624dd3
    umull r2, r3, r1, r2
    movs r3, r3, lsr #0x6
    movne r0, #0x5
    bne      L_0207a880
    ldr     r2, =0x51eb851f
    umull r2, r3, r1, r2
    movs r3, r3, lsr #0x5
    movne r0, #0x4
    bne      L_0207a880
    ldr     r2, =0xcccccccd
    umull r2, r3, r1, r2
    movs r3, r3, lsr #0x3
    movne r0, #0x3
    bne      L_0207a880
    cmp r1, #0x0
    movne r0, #0x2
    L_0207a880:
    mov r5, r0, lsl #0x2
    ldr r0, [r4, #0xec]
    rsb r1, r5, #0x6b
    mov r2, #0xa4
    bl      func_0201c1e4
    ldr r0, [r4, #0xf0]
    add r1, r5, #0x89
    mov r2, #0xa4
    bl      func_0201c1e4
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
