#include "m2c.h"

extern void func_020aaeb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020575ec(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x18
    mov r4, r1
    ldrb r5, [r4, #0x6]
    bl      func_020aaeb4
    strb r5, [r0, #0x242]
    ldrb r0, [r4, #0x6]
    cmp r0, #0x0
    addeq sp, sp, #0x18
    ldmeqia   sp!, {r3, r4, r5, pc}
    ldrsh r0, [r4, #0x4]
    mov     r0, r0, lsl 0xc
    str r0, [sp, #0x8]
    str r0, [sp, #0x14]
    bl      func_020aaeb4
    ldr r1, [sp, #0x8]
    str r1, [r0, #0x244]
    ldrsh r0, [r4, #0x2]
    mov     r0, r0, lsl 0xc
    str r0, [sp, #0x4]
    str r0, [sp, #0x10]
    bl      func_020aaeb4
    ldr r1, [sp, #0x4]
    str r1, [r0, #0x248]
    ldrsh r0, [r4, #0x0]
    mov     r0, r0, lsl 0xc
    str r0, [sp, #0x0]
    str r0, [sp, #0xc]
    bl      func_020aaeb4
    ldr r1, [sp, #0x0]
    str r1, [r0, #0x24c]
    add sp, sp, #0x18
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
