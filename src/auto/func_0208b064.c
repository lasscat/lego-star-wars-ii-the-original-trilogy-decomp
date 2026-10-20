#include "m2c.h"

extern M2C_UNK data_020f0278;

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208b064(s32 arg0, void *dest, s32 x) {
    stmdb sp!, {r3, lr}
    ldr     r0, =data_020f0278
    ldrh    lr, [r0, #0x4]
    ldrh    r3, [r0, #0x6]
    add     r0, lr, r2, lsl #0x1
    strh    r3, [sp, #0x2]
    mov     r0, r0, lsl #0x10
    mov     ip, r0, lsr #0x10
    mov     r3, r3
    add     r0, r3, r2, lsl #0x1
    mov     r0, r0, lsl #0x10
    strh    ip, [r1, #0x0]
    add     r2, ip, #0x1
    mov     r0, r0, lsr #0x10
    strh    r2, [r1, #0x2]
    strh    r0, [r1, #0x40]
    add     r0, r0, #0x1
    strh    lr, [sp, #0x0]
    strh    r0, [r1, #0x42]
    ldmfd   sp!, {r3, pc}
}
// clang-format on
