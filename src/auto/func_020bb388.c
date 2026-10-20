#include "m2c.h"

extern u32 data_0210dc2f[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bb388(s32 a0, s32 a1) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     lr, =data_0210dc2f
    and     r4, r0, #0xe0
    mvn     r3, #0x0
    mov     r5, #0xff
    mov     r0, #0xf
L_020bb3a0:
    ldrb    r2, [lr, #0x4]
    ldrb    ip, [lr, #0x14]
    cmp     r2, #0xff
    ldmeqia sp!, {r3, r4, r5, pc}
    and     r2, r2, #0xe0
    cmp     r2, #0x40
    beq     L_020bb3d8
    cmp     r2, #0x20
    bne     L_020bb3cc
    cmp     r4, #0x20
    addne   ip, ip, #0x100
L_020bb3cc:
    cmp     ip, r3
    movlo   r5, r0
    movlo   r3, ip
L_020bb3d8:
    sub     lr, lr, #0x1
    subs    r0, r0, #0x1
    bpl     L_020bb3a0
    cmp     r1, r3
    movlo   r5, #0xff
    mov     r0, r5
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
