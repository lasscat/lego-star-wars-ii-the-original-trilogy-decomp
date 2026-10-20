#include "m2c.h"

extern u32 data_02101168[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bd534(s32 a0, s32 a1) {
    ldr     r3, =data_02101168
    mov     r2, #0x1
    str     r3, [r0, #0x0]
    str     r2, [r0, #0x4]
    mov     r2, #0x3c
    str     r2, [r0, #0x8]
    str     r2, [r0, #0xc]
    mov     r2, #0x0
    str     r2, [r0, #0x10]
    str     r2, [r0, #0x14]
    str     r2, [r0, #0x18]
    strh    r2, [r0, #0x1c]
    strh    r2, [r0, #0x1e]
    strh    r2, [r0, #0x20]
    strh    r2, [r0, #0x22]
    str     r2, [r0, #0x24]
    str     r2, [r0, #0x28]
    strh    r2, [r0, #0x2c]
    strh    r2, [r0, #0x2e]
    strh    r2, [r0, #0x30]
    strh    r2, [r0, #0x32]
    str     r2, [r0, #0x34]
    str     r2, [r0, #0x38]
    str     r2, [r0, #0x3c]
    str     r2, [r0, #0x40]
    strb    r2, [r0, #0x44]
    add     ip, r0, #0x48
    add     r2, r0, #0x60
    mov     r3, #0x0
L_020bd5a8:
    str     r3, [ip, #0x0]
    strb    r3, [ip, #0x4]
    strb    r3, [ip, #0x6]
    strb    r3, [ip, #0x7]
    add     ip, ip, #0x8
    cmp     ip, r2
    blo     L_020bd5a8
    str     r1, [r0, #0x60]
    str     r3, [r0, #0x64]
    bx      lr
}
// clang-format on
