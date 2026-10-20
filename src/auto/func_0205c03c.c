#include "m2c.h"

extern void func_01ffa41c();
extern void func_01ffa430();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205c03c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r1
    mov r5, r0
    mov r0, r4
    bl      func_01ffa41c
    ldr     r1, =0xb60b60b
    mov r2, #0xb6
    umull ip, r3, r0, r1
    mla r3, r0, r2, r3
    mov     r0, r0, asr 0x1f
    mla r3, r0, r1, r3
    adds r0, ip, #0x0
    adc r0, r3, #0x800
    mov     r0, r0, asr 0xc
    strh r0, [sp, #0x2]
    ldrh r1, [sp, #0x2]
    mov r0, r4
    strh r1, [r5, #0x1c]
    strh r1, [sp, #0x0]
    bl      func_01ffa41c
    str r0, [r5, #0x14]
    mov r0, r4
    bl      func_01ffa41c
    str r0, [r5, #0x18]
    mov r0, r4
    bl      func_01ffa41c
    str r0, [r5, #0x10]
    mov r1, r4
    mov r0, r5
    bl      func_01ffa430
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
