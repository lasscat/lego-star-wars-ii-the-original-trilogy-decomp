#include "m2c.h"

extern void func_020aaeb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057670(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    ldrsh r3, [r1, #0x4]
    ldrsh r0, [r1, #0x0]
    ldrsh r2, [r1, #0x2]
    mov     r3, r3, lsl 0xc
    mov     r0, r0, lsl 0xc
    mov     r1, r2, lsl 0xc
    add r4, sp, #0x0
    str r0, [sp, #0x0]
    str r1, [sp, #0x4]
    str r3, [sp, #0x8]
    bl      func_020aaeb4
    mov r1, r4
    add r2, r0, #0x250
    cmp r2, r1
    addeq sp, sp, #0xc
    ldmeqia   sp!, {r3, r4, pc}
    ldr r1, [r4, #0x0]
    str r1, [r0, #0x250]
    ldr r1, [r4, #0x4]
    str r1, [r0, #0x254]
    ldr r1, [r4, #0x8]
    str r1, [r0, #0x258]
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
