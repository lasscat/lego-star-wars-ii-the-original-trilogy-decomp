#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202ceec(s32 a0, s32 a1) {
    movs r3, #0x0
    strb r3, [r0, #0x0]
    strb r1, [r0, #0x1]
    strb r3, [r0, #0x2]
    mov r1, #0x3
    strb r1, [r0, #0x3]
    strh r3, [r0, #0x4]
    str r3, [r0, #0x8]
    add r2, r0, #0xc
    str r3, [r2, #0x0]
    streq r3, [r2, #0x4]
    bxeq lr
    ldr r1, [r3, #0x0]
    str r1, [r2, #0x4]
    str r2, [r3, #0x0]
    bx lr
}
// clang-format on
