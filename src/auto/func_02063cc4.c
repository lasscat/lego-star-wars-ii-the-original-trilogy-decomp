#include "m2c.h"

extern void func_020b973c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02063cc4(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    add r1, r5, #0x48
    ldrb r0, [r1, r4]
    sub r0, r0, #0x1
    strb r0, [r1, r4]
    tst r0, #0xff
    ldmneia   sp!, {r3, r4, r5, pc}
    add r0, r5, r4, lsl #0x2
    ldr r0, [r0, #0x38]
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    bl      func_020b973c
    add r0, r5, r4, lsl #0x2
    mov r1, #0x0
    str r1, [r0, #0x38]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
