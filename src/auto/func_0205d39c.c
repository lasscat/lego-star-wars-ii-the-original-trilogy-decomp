#include "m2c.h"

extern u32 data_020fe614[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205d39c(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r1, =data_020fe614
    mov r4, r0
    str r1, [r4, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx      r1
    mov r0, r4
    ldmia   sp!, {r4, pc}
}
// clang-format on
