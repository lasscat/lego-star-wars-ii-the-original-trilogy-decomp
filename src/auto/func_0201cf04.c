#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201cf04(s32 a0, s32 a1) {
    and r3, r1, #0xff
    mov r2, #0x0
L_0201cf0c:
    ldr r1, [r0, r2, lsl #0x2]
    cmp r1, #0x0
    beq L_0201cf2c
    add r1, r1, #0x100
    ldrh r1, [r1, #0x80]
    cmp r3, r1
    moveq r0, r2
    bxeq lr
L_0201cf2c:
    add r2, r2, #0x1
    cmp r2, #0x8
    blo L_0201cf0c
    ldr r0, =0xffff
    bx lr
}
// clang-format on
