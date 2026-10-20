#include "m2c.h"

extern u32 data_0210dc2f[];
extern u32 data_0210daf0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020b861c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r2, =data_0210dc2f
    ldr     lr, =data_0210daf0
    mov     r1, #0xf
    mov     r3, #0x1e0
L_020b8630:
    ldr     ip, [lr, #0x0]
    ldrb    r4, [r2, #0x4]
    ldrb    r5, [ip, #0x39]
    cmp     r5, r4
    bne     L_020b866c
    add     ip, ip, #0xcd
    add     r5, ip, #0x400
    ldrb    r4, [r5, r3]
    mov     ip, r4, lsl #0x1e
    orr     ip, r0, ip, lsr #0x1e
    and     ip, ip, #0xff
    bic     r4, r4, #0x3
    and     ip, ip, #0x3
    orr     r4, r4, ip
    strb    r4, [r5, r3]
L_020b866c:
    sub     r2, r2, #0x1
    sub     r3, r3, #0x20
    subs    r1, r1, #0x1
    bpl     L_020b8630
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
