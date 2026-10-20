#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020c62a0(s32 a0, s32 a1, s32 a2) {
    ldr r3, [r0, #0x8]
    cmp r2, #0x0
    add ip, r0, r3
    ldrh r0, [ip, #0xa]
    add r3, ip, #0x4
    ldrh r2, [r3, r0]
    add r0, r3, r0
    mla r0, r2, r1, r0
    ldr r0, [r0, #0x4]
    add r1, ip, r0
    ldr r0, [r1, #0xc]
    orrne r0, r0, #0x8000
    biceq r0, r0, #0x8000
    str r0, [r1, #0xc]
    bx lr
}
// clang-format on
