#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bd720(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    ldr r3, [r0, #0x10]
    ldr r2, [sp, #0x4]
    ldr r1, [r0, #0x64]
    smull ip, r2, r3, r2
    adds r3, ip, #0x800
    adc r2, r2, #0x0
    mov r3, r3, lsr #0xc
    orr r3, r3, r2, lsl #0x14
    add r2, r1, r3
    mov r1, r1, asr #0xc
    str r2, [r0, #0x64]
    rsb r0, r1, r2, asr #0xc
    add sp, sp, #0x10
    bx lr
}
// clang-format on
