#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020966e8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r5, r0
    ldrb    r0, [r5, #0x38]
    cmp     r0, #0x0
    ldmeqfd sp!, {r3, r4, r5, pc}
    ldr     r4, [r5, #0x4]
    cmp     r4, #0x0
    beq     L_0209672c
L_02096708:
    ldr     r0, [r4, #0x0]
    cmp     r0, #0x0
    beq     L_02096720
    ldr     r1, [r0, #0x0]
    ldr     r1, [r1, #0x4]
    blx     r1
L_02096720:
    ldr     r4, [r4, #0x4]
    cmp     r4, #0x0
    bne     L_02096708
L_0209672c:
    mov     r0, r5
    ldr     r1, [r0, #0x0]
    ldr     r1, [r1, #0x18]
    blx     r1
    mov     r0, #0x0
    strb    r0, [r5, #0x38]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
