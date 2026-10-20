#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207f56c(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldr r2, [r0, #0x8]!
    ldr r2, [r2, #0x8]
    blx     r2
    ldmia   sp!, {r3, pc}
}
// clang-format on
