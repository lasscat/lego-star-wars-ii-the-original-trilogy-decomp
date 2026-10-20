#include "m2c.h"

extern u32 data_0210e3f8[];
extern u32 data_0210e2f8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c055c(s32 a0, s32 a1) {
    stmdb   sp!, {lr}
    sub     sp, sp, #0xc
    ldr     lr, [r1, #0x4c]
    ldr     r2, =data_0210e3f8
    ldr     r0, =data_0210e2f8
    ldr     r3, [r2, lr, lsl #0x2]
    ldr     ip, [r1, #0x34]
    ldr     r0, [r0, lr, lsl #0x2]
    ldr     r2, [r1, #0x30]
    ldr     lr, [r1, #0x38]
    add     r3, ip, r3
    add     ip, r2, r0
    str     ip, [sp, #0x0]
    str     r3, [sp, #0x4]
    str     lr, [sp, #0x8]
    ldr     r0, [r1, #0x30]
    cmp     r0, ip
    ldreq   r0, [r1, #0x34]
    cmpeq   r0, r3
    ldreq   r0, [r1, #0x38]
    cmpeq   r0, lr
    movne   r0, #0x1
    moveq   r0, #0x0
    cmp     r0, #0x0
    addeq   sp, sp, #0xc
    ldmeqia sp!, {pc}
    add     r0, sp, #0x0
    add     r2, r1, #0x30
    cmp     r2, r0
    beq     L_020c05e8
    str     ip, [r1, #0x30]
    ldr     r0, [sp, #0x4]
    str     r0, [r1, #0x34]
    ldr     r0, [sp, #0x8]
    str     r0, [r1, #0x38]
L_020c05e8:
    mov     r0, #0x1
    strb    r0, [r1, #0x45]
    add     sp, sp, #0xc
    ldmia   sp!, {pc}
}
// clang-format on
