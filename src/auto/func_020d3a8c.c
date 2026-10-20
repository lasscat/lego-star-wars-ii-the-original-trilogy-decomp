#include "m2c.h"

extern u32 data_0211748c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020d3a8c(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldr     r2, =data_0211748c
    ldr r1, [r2, #0x18]
    ldr ip, [r2, #0x1c]
    cmp r1, #0x0
    ldr r1, [r2, #0x20]
    movne r3, #0x0
    strne r3, [r2, #0x18]
    cmp ip, #0x0
    ldmeqia   sp!, {r3, pc}
    ldr     r2, =data_0211748c
    mov r3, #0x0
    str r3, [r2, #0x1c]
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
