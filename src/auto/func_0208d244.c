#include "m2c.h"

extern void func_0205e84c(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208d244(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r5, r0
    ldrb    r0, [r5, #0x38]
    cmp     r0, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr     r4, [r5, #0x4]
    cmp     r4, #0x0
    beq     L_0208d278
L_0208d264:
    ldr     r0, [r4, #0x0]
    bl      func_0205e84c
    ldr     r4, [r4, #0x4]
    cmp     r4, #0x0
    bne     L_0208d264
L_0208d278:
    mov     r0, r5
    ldr     r1, [r0, #0x0]
    ldr     r1, [r1, #0x18]
    blx     r1
    mov     r0, #0x0
    strb    r0, [r5, #0x38]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
