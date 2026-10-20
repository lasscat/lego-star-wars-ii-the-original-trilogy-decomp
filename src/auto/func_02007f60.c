#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02007f60(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, lr}
    ldrsb r3, [r1, #0x25]
    cmp r3, #5
    bgt    L_02007f90
    cmp r3, #0
    blt    L_020081e4
    beq    L_02007f9c
    cmp r3, #3
    beq    L_02007fd4
    cmp r3, #5
    beq    L_02008084
    b      L_020081e4
L_02007f90:
    cmp r3, #11
    beq    L_02008134
    b      L_020081e4
L_02007f9c:
    ldrsb r1, [r2, #0x25]
    cmp r1, #5
    bgt    L_02007fc0
    cmp r1, #0
    blt    L_020081e4
    beq    L_02007fc8
    cmp r1, #3
    cmpne r1, #5
    b      L_020081e4
L_02007fc0:
    cmp r1, #11
    b      L_020081e4
L_02007fc8:
    mov r1, #0
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_02007fd4:
    ldrsb r3, [r2, #0x25]
    cmp r3, #5
    bgt    L_02008000
    cmp r3, #0
    blt    L_020081e4
    beq    L_020081e4
    cmp r3, #3
    beq    L_0200800c
    cmp r3, #5
    beq    L_02008034
    b      L_020081e4
L_02008000:
    cmp r3, #11
    beq    L_0200805c
    b      L_020081e4
L_0200800c:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x28]
    sub r12, lr, r12
    ldr r1, [r2, #0x28]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_02008034:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x28]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_0200805c:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x28]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_02008084:
    ldrsb r3, [r2, #0x25]
    cmp r3, #5
    bgt    L_020080b0
    cmp r3, #0
    blt    L_020081e4
    beq    L_020081e4
    cmp r3, #3
    beq    L_020080bc
    cmp r3, #5
    beq    L_020080e4
    b      L_020081e4
L_020080b0:
    cmp r3, #11
    beq    L_0200810c
    b      L_020081e4
L_020080bc:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x28]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_020080e4:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_0200810c:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_02008134:
    ldrsb r3, [r2, #0x25]
    cmp r3, #5
    bgt    L_02008160
    cmp r3, #0
    blt    L_020081e4
    beq    L_020081e4
    cmp r3, #3
    beq    L_0200816c
    cmp r3, #5
    beq    L_02008194
    b      L_020081e4
L_02008160:
    cmp r3, #11
    beq    L_020081bc
    b      L_020081e4
L_0200816c:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x28]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_02008194:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_020081bc:
    ldr lr, [r2, #8]
    ldr ip, [r1, #8]
    ldr r3, [r1, #0x2c]
    sub r12, lr, r12
    ldr r1, [r2, #0x2c]
    add r2, r12, r3
    add r1, r2, r1
    add r1, r1, #1
    str r1, [r0]
    ldmia sp!, {r3, pc}
L_020081e4:
    mov r1, #0
    str r1, [r0]
    ldmia sp!, {r3, pc}
}
// clang-format on
