#include "m2c.h"

extern void func_020aaeb4();
extern void func_020a2064();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020575a8(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrsh r2, [r1, #0x0]
    ldr     r1, =0xb60b60b7
    mov     r3, r2, lsl 0x10
    smull r0, ip, r1, r3
    add ip, ip, r2, lsl #0x10
    mov     r0, r3, lsr 0x1f
    add ip, r0, ip, asr #0x8
    strh ip, [sp, #0x0]
    bl      func_020aaeb4
    ldrh r1, [sp, #0x0]
    sub r2, sp, #0x4
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_020a2064
    ldmia   sp!, {r3, pc}
}
// clang-format on
