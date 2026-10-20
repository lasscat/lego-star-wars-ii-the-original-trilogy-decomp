#include "m2c.h"

extern void func_02060fa4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02050f24(s32 a0) {
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x20
    mov r1, #0x0
    str r1, [sp, #0x14]
    str r1, [sp, #0x18]
    str r1, [sp, #0x1c]
    ldrsh r2, [r0, #0x0]
    add r1, sp, #0x8
    mov     r2, r2, lsl 0xc
    str r2, [sp, #0x14]
    ldrsh r2, [r0, #0x2]
    mov     r2, r2, lsl 0xc
    str r2, [sp, #0x18]
    ldrsh r2, [r0, #0x4]
    mov     r2, r2, lsl 0xc
    str r2, [sp, #0x1c]
    ldrh ip, [r0, #0xc]
    mov     r3, ip, asr 0x5
    mov     r2, ip, asr 0xa
    mov     ip, ip, lsl 0x1b
    mov     r3, r3, lsl 0x1b
    mov     r2, r2, lsl 0x1b
    mov     ip, ip, lsr 0xf
    mov     r3, r3, lsr 0xf
    mov     r2, r2, lsr 0xf
    str ip, [sp, #0x8]
    str r3, [sp, #0xc]
    str r2, [sp, #0x10]
    ldrh r3, [r0, #0xa]
    ldrh r2, [r0, #0x8]
    add r0, sp, #0x14
    mov     r3, r3, lsl 0xc
    mov     r2, r2, lsl 0xc
    str r3, [sp, #0x0]
    str r2, [sp, #0x4]
    bl      func_02060fa4
    add sp, sp, #0x20
    ldmia   sp!, {r3, pc}
}
// clang-format on
