#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201eec4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, lr}
    ldr r4, =0x0
    ldr r2, [sp, #0x10]
    mov r3, r4
    ldr r3, [r0, #0x0]
    ldr lr, [r1, #0x0]
    sub r3, r3, lr
    ldr ip, [r0, #0x8]
    ldr lr, [r1, #0x8]
    sub ip, ip, lr
    smull r3, lr, r3, r3
    smlal r3, lr, ip, ip
    smull r0, ip, r2, r2
    subs r0, r3, r0
    sbc r0, lr, ip
    mov r3, r0, lsr #0x1f
    cmp r3, #0x0
    beq L_0201ef14
    mov r4, #0x1
L_0201ef14:
    mov r0, r4
    ldmfd sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
