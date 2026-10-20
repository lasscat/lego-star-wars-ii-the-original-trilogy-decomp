#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02025198(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrb    r1, [r0, #0x230]
    mov     r2, #0x0
    cmp     r1, #0x0
    ldmleia sp!, {r3, pc}
    add     r1, r0, #0x220
L_020251b0:
    add     r3, r0, r2, lsl #0x3
    ldr     lr, [r3, #0x220]
    mov     r3, lr
    cmp     lr, #0x0
    subne   r3, lr, #0x4
    cmp     r3, #0x0
    beq     L_0202524c
    cmp     lr, #0x0
    subne   lr, lr, #0x4
    ldr     ip, [lr, #0x8]
    add     r3, r0, r2, lsl #0x3
    orr     ip, ip, #0x2
    str     ip, [lr, #0x8]
    ldr     ip, [r3, #0x220]
    mov     lr, #0x0
    cmp     ip, #0x0
    beq     L_0202521c
    ldr     r3, [ip, #0x0]
    cmp     r3, r1
    beq     L_02025210
L_02025200:
    add     ip, r3, #0x4
    ldr     r3, [r3, #0x4]
    cmp     r3, r1
    bne     L_02025200
L_02025210:
    add     r3, r0, r2, lsl #0x3
    ldr     r3, [r3, #0x224]
    str     r3, [ip, #0x0]
L_0202521c:
    cmp     lr, #0x0
    beq     L_0202523c
    add     ip, r0, r2, lsl #0x3
    str     lr, [ip, #0x220]
    ldr     r3, [lr, #0x0]
    str     r3, [ip, #0x224]
    str     r1, [lr, #0x0]
    b       L_0202524c
L_0202523c:
    add     r3, r0, r2, lsl #0x3
    mov     ip, #0x0
    str     ip, [r3, #0x220]
    str     ip, [r3, #0x224]
L_0202524c:
    ldrb    r3, [r0, #0x230]
    add     r2, r2, #0x1
    add     r1, r1, #0x8
    cmp     r2, r3
    blt     L_020251b0
    ldmfd   sp!, {r3, pc}
}
// clang-format on
