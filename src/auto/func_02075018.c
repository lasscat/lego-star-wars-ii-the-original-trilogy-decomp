#include "m2c.h"

extern void func_0205e84c(s32 *);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02075018(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r4, r0
    ldr     r5, [r4, #0x0]
    ldr     r1, [r4, #0x4]
    add     r0, r5, r1, lsl #0x2
    cmp     r5, r0
    beq     L_0207504c
L_02075034:
    ldr     r0, [r5], #0x4
    bl      func_0205e84c
    ldmia   r4, {r0, r1}
    add     r0, r0, r1, lsl #0x2
    cmp     r5, r0
    bne     L_02075034
L_0207504c:
    mov     r0, #0x0
    strb    r0, [sp, #0x0]
    ldr     r0, [r4, #0x4]
    sub     r0, r0, r1
    str     r0, [r4, #0x4]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
