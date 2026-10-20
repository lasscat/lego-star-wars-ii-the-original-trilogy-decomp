#include "m2c.h"

extern void func_0201b614();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201b1fc(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    mov r1, #0x1
    bl      func_0201b614
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx      r1
    ldrb r0, [r4, #0x45]
    tst r0, #0x10
    ldmeqia   sp!, {r4, pc}
    ldr r1, [r4, #0x10]
    mov r0, r4
    orr r1, r1, #0x10000000
    str r1, [r4, #0x10]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx      r1
    ldr r0, [r4, #0x10]
    bic r0, r0, #0x10000000
    str r0, [r4, #0x10]
    ldmia   sp!, {r4, pc}
}
// clang-format on
