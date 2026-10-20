#include "m2c.h"

extern u32 data_0210e6f4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bec84(s32 a0, s32 a1) {
    stmdb   sp!, {r4, r5, lr}
    sub     sp, sp, #0xc
    ldr     r2, [r1, #0x4c]
    mov     r0, #0xc
    mul     r0, r2, r0
    ldr     r5, =data_0210e6f4
    ldr     r4, [r1, #0x5c]
    add     r2, r5, r0
    ldmib   r2, {r3, lr}
    ldr     ip, [r1, #0x58]
    ldr     r2, [r1, #0x54]
    add     r4, r4, lr
    add     ip, ip, r3
    ldr     r0, [r5, r0]
    str     ip, [sp, #0x4]
    add     r3, r2, r0
    add     r0, sp, #0x0
    add     r2, r1, #0x54
    str     r3, [sp, #0x0]
    str     r4, [sp, #0x8]
    cmp     r2, r0
    addeq   sp, sp, #0xc
    ldmeqia sp!, {r4, r5, pc}
    str     r3, [r1, #0x54]
    ldr     r0, [sp, #0x4]
    str     r0, [r1, #0x58]
    ldr     r0, [sp, #0x8]
    str     r0, [r1, #0x5c]
    add     sp, sp, #0xc
    ldmfd   sp!, {r4, r5, pc}
}
// clang-format on
