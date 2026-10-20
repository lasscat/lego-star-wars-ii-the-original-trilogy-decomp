#include "m2c.h"

extern u32 data_027e02a8[];
extern u32 data_021041c1[];
extern u32 data_021041c2[];
extern u32 data_021041c0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060e6c(s32 a0) {
    ldr     r1, [r0, #0x8]
    and     r1, r1, #0x80000
    cmp     r1, #0x80000
    bxne    lr
    ldr     r2, [r0, #0x8]
    ldr     r1, =data_027e02a8
    bic     r2, r2, #0x80000
    str     r2, [r0, #0x8]
    ldr     r2, [r0, #0x14]
    ldr     r1, [r1, #0x0]
    mov     r2, r2, lsl #0x10
    tst     r1, #0x200
    mov     ip, r2, lsr #0x1c
    movne   r1, #0x0
    bne     L_02060eb8
    ldr     r0, [r0, #0x8]
    tst     r0, #0x80000000
    movne   r1, #0x0
    moveq   r1, #0x1
L_02060eb8:
    mov     r0, #0x84
    mul     r3, r1, r0
    ldr     r0, =data_021041c1
    mov     r2, ip, lsl #0x3
    add     r1, r0, r3
    ldrb    r0, [r1, ip, lsl #0x3]
    cmp     r0, #0x0
    bxeq    lr
    ldrb    r0, [r1, r2]
    sub     r0, r0, #0x1
    strb    r0, [r1, r2]
    tst     r0, #0xff
    bxne    lr
    ldr     r0, =data_021041c2
    add     r0, r0, r3
    ldrb    r0, [r2, r0]
    tst     r0, #0x2
    bxne    lr
    ldr     r0, =data_021041c0
    mov     r1, #0xff
    add     r0, r0, r3
    strb    r1, [r2, r0]
    bx      lr
}
// clang-format on
