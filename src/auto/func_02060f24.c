#include "m2c.h"

extern u32 data_021041bc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060f24(s32 a0, s32 a1) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r3, =data_021041bc
    mov     r2, #0x84
    mla     r5, r1, r2, r3
    mov     lr, #0x0
    mov     ip, #0xff
    mov     r3, lr
L_02060f40:
    add     r2, r5, lr, lsl #0x3
    ldrb    r1, [r2, #0x6]
    tst     r1, #0x2
    bne     L_02060f8c
    ldrb    r1, [r2, #0x4]
    cmp     r1, #0xff
    bne     L_02060f68
    cmp     ip, #0xff
    moveq   ip, lr
    b       L_02060f8c
L_02060f68:
    ldr     r1, [r2, #0x8]
    ldrh    r2, [r0, #0x0]
    ldrh    r1, [r1, #0x0]
    mov     r4, r3
    cmp     r2, r1
    addeq   r4, r3, #0x1
    cmp     r4, #0x1
    moveq   ip, lr
    beq     L_02060f98
L_02060f8c:
    add     lr, lr, #0x1
    cmp     lr, #0xf
    bls     L_02060f40
L_02060f98:
    mov     r0, ip
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
