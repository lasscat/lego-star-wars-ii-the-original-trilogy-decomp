#include "m2c.h"

extern u32 data_0210e2f8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020be88c(s32 a0, s32 a1) {
    stmdb   sp!, {r3}
    sub     sp, sp, #0xc
    ldr     r2, [r1, #0x4c]
    ldr     r0, =data_0210e2f8
    ldr     r3, [r1, #0x38]
    ldr     ip, [r0, r2, lsl #0x2]
    ldr     r2, [r1, #0x34]
    ldr     r0, [r1, #0x30]
    add     r3, r3, ip
    add     r2, r2, ip
    add     ip, r0, ip
    str     ip, [sp, #0x0]
    str     r2, [sp, #0x4]
    str     r3, [sp, #0x8]
    ldr     r0, [r1, #0x30]
    cmp     r0, ip
    ldreq   r0, [r1, #0x34]
    cmpeq   r0, r2
    ldreq   r0, [r1, #0x38]
    cmpeq   r0, r3
    movne   r0, #0x1
    moveq   r0, #0x0
    cmp     r0, #0x0
    addeq   sp, sp, #0xc
    ldmeqfd sp!, {r3}
    bxeq    lr
    add     r0, sp, #0x0
    add     r2, r1, #0x30
    cmp     r2, r0
    beq     L_020be918
    str     ip, [r1, #0x30]
    ldr     r0, [sp, #0x4]
    str     r0, [r1, #0x34]
    ldr     r0, [sp, #0x8]
    str     r0, [r1, #0x38]
L_020be918:
    mov     r0, #0x1
    strb    r0, [r1, #0x45]
    add     sp, sp, #0xc
    ldmfd   sp!, {r3}
    bx      lr
}
// clang-format on
