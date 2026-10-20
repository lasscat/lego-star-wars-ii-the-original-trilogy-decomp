#include "m2c.h"

extern u32 data_02108d84[];
extern u32 data_020f86f8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02086f98() {
    stmdb   sp!, {r4, lr}
    ldr     r1, =data_02108d84
    ldr     r0, =0x16d
    ldr     r2, [r1, #0x4b8]
    ldr     ip, [r1, #0x4bc]
    add     r2, r2, #0x7d0
    sub     r4, r2, #0x7d0
    mul     r3, r4, r0
    ldr     r0, =data_020f86f8
    sub     r2, ip, #0x1
    ldr     lr, [r1, #0x4c0]
    add     r1, r3, r4, asr #0x2
    ldr     r0, [r0, r2, lsl #0x2]
    add     r1, lr, r1
    tst     r4, #0x3
    add     r0, r1, r0
    bne     L_02086fe4
    cmp     ip, #0x2
    ble     L_02086fec
L_02086fe4:
    mov     r1, #0x1
    b       L_02086ff0
L_02086fec:
    mov     r1, #0x0
L_02086ff0:
    ldr     r2, =data_02108d84
    add     r4, r0, r1
    ldr     r1, [r2, #0x4c8]
    mov     r0, #0xe10
    mul     r3, r1, r0
    ldr     ip, [r2, #0x4cc]
    mov     r1, #0x3c
    ldr     r0, =0x15180
    sub     lr, r4, #0x1
    mul     r4, lr, r0
    mla     r0, ip, r1, r3
    ldr     r1, [r2, #0x4d0]
    add     r3, r4, #0x80000000
    add     r0, r1, r0
    add     r0, r3, r0
    str     r0, [r2, #0x4d4]
    ldmfd   sp!, {r4, pc}
}
// clang-format on
