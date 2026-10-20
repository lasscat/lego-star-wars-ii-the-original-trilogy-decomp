#include "m2c.h"

extern void func_0205e068();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205d614(s32 a0) {
    stmdb   sp!, {r3, lr}
    cmp r1, #0x0
    ldmeqia   sp!, {r3, pc}
    ldr r3, [r1, #0x8]
    cmp r3, #0x0
    ldrne r2, [r1, #0x4]
    strne r2, [r3, #0x4]
    ldr r3, [r1, #0x4]
    cmp r3, #0x0
    ldrne r2, [r1, #0x8]
    strne r2, [r3, #0x8]
    ldr r2, [r0, #0x4]
    cmp r1, r2
    ldreq r2, [r1, #0x4]
    streq r2, [r0, #0x4]
    ldr r2, [r0, #0x8]
    cmp r1, r2
    ldreq r2, [r1, #0x8]
    streq r2, [r0, #0x8]
    ldr r0, [r0, #0x10]
    bl      func_0205e068
    ldmia   sp!, {r3, pc}
}
// clang-format on
