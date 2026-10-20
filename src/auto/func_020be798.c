#include "m2c.h"

extern M2C_UNK data_0210e1f8;

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020be798(s32 arg0, s32 arg1, ...) {
    stmfd sp!, {r0, r1, r2, r3}
    sub     sp, sp, #0x8
    ldr     r3, [r1, #0x4c]
    ldr     r0, =data_0210e1f8
    ldr     r2, [sp, #0x10]
    ldr     r3, [r0, r3, lsl #0x2]
    ldr     r0, [r1, #0x6c]
    smull   ip, r2, r3, r2
    adds    r3, ip, #0x800
    adc     r2, r2, #0x0
    mov     r3, r3, lsr #0xc
    orr     r3, r3, r2, lsl #0x14
    add     r0, r0, r3
    str     r0, [sp, #0x4]
    str     r0, [sp, #0x0]
    str     r0, [r1, #0x6c]
    add     sp, sp, #0x8
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
