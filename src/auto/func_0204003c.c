#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204003c(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r2, r0
    cmp r1, #0x0
    ldmeqia   sp!, {r3, pc}
    ldrh r0, [r1, #0xc]
    tst r0, #0x3
    ldmeqia   sp!, {r3, pc}
    mov r0, r1
    ldr ip, [r0, #0x0]
    mov r1, r2
    ldr ip, [ip, #0x2c]
    mov r2, #0x1
    mov r3, #0x0
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
