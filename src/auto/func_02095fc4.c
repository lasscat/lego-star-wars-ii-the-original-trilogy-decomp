#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02095fc4(s32 a0, s32 a1, s32 a2, s32 a3) {
    ldr ip, [r0, #0x304]
    add ip, ip, ip, lsl #0x1
    add ip, r0, ip
    strb r2, [ip, #0x4]
    ldr r2, [r0, #0x304]
    add r2, r2, r2, lsl #0x1
    add r2, r0, r2
    strb r3, [r2, #0x5]
    ldr r3, [r0, #0x0]
    ldr r2, [r0, #0x304]
    ldrb r3, [r3, r1]
    add r2, r2, r2, lsl #0x1
    add r2, r0, r2
    strb r3, [r2, #0x6]
    ldr r3, [r0, #0x304]
    ldr r2, [r0, #0x0]
    strb r3, [r2, r1]
    ldr r1, [r0, #0x304]
    add r1, r1, #0x1
    str r1, [r0, #0x304]
    bx lr
}
// clang-format on
