#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02083bdc(s32 a0, s32 a1, s32 a2) {
    cmp r2, #0x0
    moveq r0, #0x0
    bxeq lr
    ldr r3, [r0, #0x54]
    ldr r1, [r3, r1, lsl #0x2]
    add r1, r1, r2
    ldrb r1, [r1, #-0x1]
    cmp r1, #0xff
    ldrne r0, [r0, r1, lsl #0x2]
    moveq r0, #0x0
    bx lr
}
// clang-format on
