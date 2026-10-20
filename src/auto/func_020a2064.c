#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020a2064(s32 a0, ...) {
    stmdb   sp!, {r0, r1, r2, r3}
    sub     sp, sp, #0x8
    ldrh    r2, [sp, #0xc]
    add     r1, r0, #0x200
    mov     ip, #0x0
    strh    r2, [r1, #0x70]
    strb    ip, [r0, #0x278]
    ldrsh   r3, [r1, #0x72]
    ldrsh   r2, [r1, #0x70]
    cmp     r2, r3
    ble     L_020a20c8
    mov     r2, #0x1
    strb    r2, [r0, #0x278]
    ldrsh   r2, [r1, #0x72]
    ldrsh   r0, [r1, #0x70]
    sub     r0, r0, r2
    add     r0, r0, r0, lsr #0x1f
    add     r0, r2, r0, asr #0x1
    strh    r0, [sp, #0x6]
    ldrh    r0, [sp, #0x6]
    strh    r0, [sp, #0x2]
    add     sp, sp, #0x8
    strh    r0, [r1, #0x76]
    add     sp, sp, #0x10
    bx      lr
L_020a20c8:
    addge   sp, sp, #0x8
    addge   sp, sp, #0x10
    bxge    lr
    sub     r2, ip, #0x1
    strb    r2, [r0, #0x278]
    ldrsh   r2, [r1, #0x70]
    ldrsh   r0, [r1, #0x72]
    sub     r0, r0, r2
    add     r0, r0, r0, lsr #0x1f
    add     r0, r2, r0, asr #0x1
    strh    r0, [sp, #0x4]
    ldrh    r0, [sp, #0x4]
    strh    r0, [sp, #0x0]
    strh    r0, [r1, #0x76]
    add     sp, sp, #0x8
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
