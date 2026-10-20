#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0207b540(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r6, #0x56000
    ldr     r5, =0x66666667
    mov     r2, #0x0
    mov     r3, #0x41
    mov     r1, r6
    mov     r4, #0x5
L_0207b55c:
    ldr     ip, [r0, #0x30]
    cmp     r2, #0x4
    add     r7, ip, r2
    mov     ip, r7, lsr #0x1f
    smull   lr, r8, r5, r7
    add     r8, ip, r8, asr #0x1
    smull   ip, lr, r4, r8
    sub     r8, r7, ip
    blt     L_0207b5a8
    ldr     lr, [r0, #0x34]
    cmp     lr, #0x0
    ble     L_0207b5a8
    add     ip, r0, r8, lsl #0x2
    add     lr, lr, #0x17
    ldr     ip, [ip, #0x1c]
    mov     lr, lr, lsl #0xc
    str     lr, [ip, #0x4c]
    str     r1, [ip, #0x50]
    b       L_0207b5c4
L_0207b5a8:
    ldr     lr, [r0, #0x34]
    add     ip, r0, r8, lsl #0x2
    add     lr, lr, r3
    ldr     ip, [ip, #0x1c]
    mov     lr, lr, lsl #0xc
    str     lr, [ip, #0x4c]
    str     r6, [ip, #0x50]
L_0207b5c4:
    add     r2, r2, #0x1
    cmp     r2, #0x5
    add     r3, r3, #0x2a
    blt     L_0207b55c
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
