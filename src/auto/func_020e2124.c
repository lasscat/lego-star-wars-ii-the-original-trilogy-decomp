#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020e2124(s32 a0, s32 a1) {
    tst     r1, #0x80000000
    bne     L_020e2188
    ldr     r2, =0x43e
    subs    r2, r2, r1, lsr #0x14
    blt     L_020e21a0
    cmp     r2, #0x40
    bge     L_020e217c
    mov     ip, r1, lsl #0xb
    orr     ip, ip, #0x80000000
    orr     ip, ip, r0, lsr #0x15
    cmp     r2, #0x20
    ble     L_020e2164
    sub     r2, r2, #0x20
    mov     r1, #0x0
    mov     r0, ip, lsr r2
    bx      lr
L_020e2164:
    mov     r3, r0, lsl #0xb
    mov     r1, ip, lsr r2
    mov     r0, r3, lsr r2
    rsb     r2, r2, #0x20
    orr     r0, r0, ip, lsl r2
    bx      lr
L_020e217c:
    mov     r1, #0x0
    mov     r0, #0x0
    bx      lr
L_020e2188:
    cmn     r1, #0x100000
    cmpeq   r0, #0x0
    bhi     L_020e21a0
    mov     r1, #0x0
    mov     r0, #0x0
    bx      lr
L_020e21a0:
    mvn     r1, #0x0
    mvn     r0, #0x0
    bx      lr
}
// clang-format on
