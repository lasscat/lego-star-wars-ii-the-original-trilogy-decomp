#include "m2c.h"

extern void func_020aaeb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057880(s32 a0) {
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x18
    ldrsh r3, [r1, #0x0]
    ldrsh r2, [r1, #0x2]
    ldrsh r0, [r1, #0x4]
    mov     ip, r3, lsl 0xc
    mov     r2, r2, lsl 0xc
    mov     r1, r0, lsl 0xc
    add r0, sp, #0xc
    add r3, sp, #0x0
    str ip, [sp, #0xc]
    str r2, [sp, #0x10]
    str r1, [sp, #0x14]
    ldmfd r0, {r0, r1, r2}
    stmea r3, {r0, r1, r2}
    bl      func_020aaeb4
    add r1, sp, #0x0
    add r2, r0, #0x2bc
    cmp r2, r1
    addeq sp, sp, #0x18
    ldmeqia   sp!, {r3, pc}
    ldr r1, [sp, #0x0]
    str r1, [r0, #0x2bc]
    ldr r1, [sp, #0x4]
    str r1, [r0, #0x2c0]
    ldr r1, [sp, #0x8]
    str r1, [r0, #0x2c4]
    add sp, sp, #0x18
    ldmia   sp!, {r3, pc}
}
// clang-format on
