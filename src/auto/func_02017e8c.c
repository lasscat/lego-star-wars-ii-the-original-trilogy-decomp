#include "m2c.h"

// clang-format off
asm void func_02017e8c(s32 a0, s32 a1) {
    stmdb sp!, {r3, lr}
    ldr r2, [r0, #0x20]
    cmp r2, #0x0
    beq L_02017eb0
    mov r0, r2
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x4]
    blx r2
    ldmia sp!, {r3, pc}
L_02017eb0:
    ldr r2, [r0, #0xb0]
    str r2, [r1, #0x0]
    ldr r2, [r0, #0xb0]
    str r2, [r1, #0x4]
    ldr r2, [r0, #0xb4]
    str r2, [r1, #0x8]
    ldr r2, [r0, #0xb4]
    str r2, [r1, #0xc]
    ldr r2, [r0, #0xb8]
    str r2, [r1, #0x10]
    ldr r0, [r0, #0xb8]
    str r0, [r1, #0x14]
    ldmia sp!, {r3, pc}
}
// clang-format on
