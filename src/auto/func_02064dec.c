#include "m2c.h"

extern u32 data_021045fc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02064dec(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r3, =0xffff
    cmp     r0, r3
    ldmeqia sp!, {r3, r4, r5, pc}
    add     r5, r0, r1
    cmp     r0, r5
    ldmhsia sp!, {r3, r4, r5, pc}
    ldr     r1, =data_021045fc
    mov     ip, #0x1
    add     r3, r1, r2, lsl #0x7
    mov     lr, #0xff
L_02064e18:
    mov     r4, r0, lsr #0x3
    ands    r2, r0, #0x7
    bne     L_02064e38
    sub     r1, r5, r0
    cmp     r1, #0x8
    movhs   r1, lr
    addhs   r0, r0, #0x8
    bhs     L_02064e40
L_02064e38:
    mov     r1, ip, lsl r2
    add     r0, r0, #0x1
L_02064e40:
    ldrb    r2, [r3, r4]
    mvn     r1, r1
    cmp     r0, r5
    and     r1, r2, r1
    strb    r1, [r3, r4]
    blo     L_02064e18
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
