#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205b1e0(s32 a0, s32 a1, s32 a2) {
    cmp r2, #0x0
    beq L_0205b22c
    ldr r2, [r1, #0x8]
    mov r0, r2, lsl #0x8
    movs r0, r0, lsr #0x1f
    bne L_0205b20c
    orr r2, r2, #0x800000
    bic r0, r2, #0x7f0000
    orr r0, r0, #0x10000
    str r0, [r1, #0x8]
    bx lr
L_0205b20c:
    mov r0, r2, lsl #0x9
    mov r0, r0, lsr #0x19
    add r0, r0, #0x1
    bic r2, r2, #0x7f0000
    mov r0, r0, lsl #0x19
    orr r0, r2, r0, lsr #0x9
    str r0, [r1, #0x8]
    bx lr
L_0205b22c:
    ldr r0, [r1, #0x8]
    mov r2, r0, lsl #0x8
    movs r2, r2, lsr #0x1f
    biceq r0, r0, #0x7f0000
    orreq r0, r0, #0xa0000
    streq r0, [r1, #0x8]
    bx lr
}
// clang-format on
