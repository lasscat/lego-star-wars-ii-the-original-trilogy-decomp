#include "m2c.h"

extern void func_020985d8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020a15b8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x20
    ldr     r2, =0x38e
    mov r4, r0
    ldr r3, [r4, #0x1d0]
    strh r2, [sp, #0x8]
    ldrh ip, [sp, #0x8]
    ldr r0, [r3, #0xb0]
    ldr r5, [r3, #0xb8]
    mov lr, #0x0
    strb r1, [r4, #0x36c]
    add r1, r4, #0x300
    strh ip, [r1, #0x72]
    ldrsb r3, [r1, #0x6c]
    sub r2, lr, #0x1
    str r0, [sp, #0x14]
    str r5, [sp, #0x1c]
    str lr, [sp, #0x18]
    strh ip, [sp, #0x4]
    cmp r3, r2
    addne sp, sp, #0x20
    ldmneia   sp!, {r3, r4, r5, pc}
    ldrh r2, [r1, #0x6e]
    mov r1, r5
    str r5, [sp, #0x10]
    strh r2, [sp, #0x2]
    str r0, [sp, #0xc]
    bl      func_020985d8
    ldrh r1, [sp, #0x2]
    mov     r0, r0, lsl 0x10
    cmp r1, r0, lsr #0x10
    addls sp, sp, #0x20
    ldmlsia   sp!, {r3, r4, r5, pc}
    ldr     r1, =0xfc72
    add r0, r4, #0x300
    strh r1, [sp, #0x6]
    ldrh r1, [sp, #0x6]
    strh r1, [sp, #0x0]
    strh r1, [r0, #0x72]
    add sp, sp, #0x20
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
