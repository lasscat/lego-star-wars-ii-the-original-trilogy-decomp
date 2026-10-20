#include "m2c.h"

extern void func_020b973c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202fa64(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldr r0, [r4, #0x2c]
    cmp r0, #0x0
    ldmeqia   sp!, {r4, pc}
    ldr r2, [r4, #0x4]
    ldr     r1, =0x802
    ldr r2, [r2, #0x8]
    tst r2, r1
    ldreqb r1, [r0, #0x1a]
    orreq r1, r1, #0x1
    streqb r1, [r0, #0x1a]
    ldmeqia   sp!, {r4, pc}
    bl      func_020b973c
    mov r0, #0x0
    str r0, [r4, #0x2c]
    ldmia   sp!, {r4, pc}
}
// clang-format on
