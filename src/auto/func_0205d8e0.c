#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205d8e0(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr r2, [r0, #0x0]
    mov r4, r0
    ldr r2, [r2, #0x34]
    blx      r2
    movs r1, r0
    addne r1, r1, #0x4
    cmp r1, #0x0
    ldmeqia   sp!, {r4, pc}
    mov r0, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x28]
    blx      r2
    ldrh r0, [r4, #0xc]
    sub r0, r0, #0x1
    strh r0, [r4, #0xc]
    ldmia   sp!, {r4, pc}
}
// clang-format on
