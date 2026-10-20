#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02062868(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r3, #0x0
    cmp r2, #0x2
    movge r3, #0x1
    mov r2, #0x38
    mul r2, r3, r2
    ldr r2, [r0, r2]!
    ldr r2, [r2, #0xc]
    blx     r2
    ldmia   sp!, {r3, pc}
}
// clang-format on
