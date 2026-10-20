#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020af3e4(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr r1, [r0, #0x0]
    mov r4, r0
    ldr r1, [r1, #0x4]
    blx     r1
    ldrb r2, [r0, #0x6e]
    add r1, r4, #0x600
    add r2, r2, #0x1
    strb r2, [r0, #0x6e]
    ldrb r0, [r4, #0x6ae]
    ldr r2, [r4, #0x6a0]
    mov     r0, r0, lsl 0x1d
    add r0, r4, r0, lsr #0x1a
    str r2, [r0, #0x6b8]
    ldrh r1, [r1, #0xa8]
    add r0, r0, #0x600
    strh r1, [r0, #0xb4]
    ldmia   sp!, {r4, pc}
}
// clang-format on
