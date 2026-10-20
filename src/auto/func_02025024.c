#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02025024(s32 a0, s32 a1) {
    stmdb   sp!, {r3, lr}
    ldrb    lr, [r0, #0x230]
    mov     r2, #0x0
    cmp     lr, #0x0
    ldmleia sp!, {r3, pc}
L_02025038:
    add     r3, r0, r2, lsl #0x3
    ldr     ip, [r3, #0x220]
    mov     r3, ip
    cmp     ip, #0x0
    subne   r3, ip, #0x4
    cmp     r3, #0x0
    bne     L_020250d8
    cmp     r1, #0x0
    addne   r1, r1, #0x4
    cmp     ip, #0x0
    beq     L_0202509c
    add     r3, r0, r2, lsl #0x3
    ldr     ip, [r3, #0x220]
    add     r3, r0, #0x220
    ldr     lr, [ip, #0x0]
    add     r3, r3, r2, lsl #0x3
    cmp     lr, r3
    beq     L_02025090
L_02025080:
    add     ip, lr, #0x4
    ldr     lr, [lr, #0x4]
    cmp     lr, r3
    bne     L_02025080
L_02025090:
    add     r3, r0, r2, lsl #0x3
    ldr     r3, [r3, #0x224]
    str     r3, [ip, #0x0]
L_0202509c:
    cmp     r1, #0x0
    beq     L_020250c4
    add     ip, r0, r2, lsl #0x3
    str     r1, [ip, #0x220]
    ldr     r3, [r1, #0x0]
    add     r0, r0, #0x220
    str     r3, [ip, #0x224]
    add     r0, r0, r2, lsl #0x3
    str     r0, [r1, #0x0]
    ldmfd   sp!, {r3, pc}
L_020250c4:
    add     r0, r0, r2, lsl #0x3
    mov     r1, #0x0
    str     r1, [r0, #0x220]
    str     r1, [r0, #0x224]
    ldmfd   sp!, {r3, pc}
L_020250d8:
    add     r2, r2, #0x1
    cmp     r2, lr
    blt     L_02025038
    ldmfd   sp!, {r3, pc}
}
// clang-format on
