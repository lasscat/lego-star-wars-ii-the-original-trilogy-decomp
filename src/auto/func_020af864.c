#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020af864(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    strb r4, [r5, #0x6f4]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx     r1
    strb r4, [r0, #0x6d]
    mov r0, r5
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx     r1
    mov r1, #0x0
    strb r1, [r0, #0x6e]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
