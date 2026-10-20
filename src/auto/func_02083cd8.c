#include "m2c.h"

extern void func_02083bdc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02083cd8(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r1
    mov r1, r2
    mov r2, r3
    bl      func_02083bdc
    movs r1, r0
    ldmeqia   sp!, {r4, pc}
    mov r0, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x1c]
    blx      r2
    ldmia   sp!, {r4, pc}
}
// clang-format on
