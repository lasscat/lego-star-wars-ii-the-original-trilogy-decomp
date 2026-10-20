#include "m2c.h"

extern void func_01ffa41c();
extern void func_01ffa430();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205bec8(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0xc
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
    strh r0, [sp, #0xa]
    ldrh r1, [sp, #0xa]
    mov r0, r4
    strh r1, [sp, #0x4]
    strh r1, [r5, #0x1e]
    bl      func_01ffa41c
    ldr     r1, =0xb60b60b
    mov r2, #0xb6
    umull ip, r3, r0, r1
    mla r3, r0, r2, r3
    mov     r0, r0, asr 0x1f
    mla r3, r0, r1, r3
    adds ip, ip, #0x0
    adc r0, r3, #0x800
    mov     r0, r0, asr 0xc
    strh r0, [sp, #0x8]
    ldrh r1, [sp, #0x8]
    mov r0, r4
    strh r1, [sp, #0x2]
    strh r1, [r5, #0x1c]
    bl      func_01ffa41c
    ldr     r1, =0xb60b60b
    mov r2, #0xb6
    umull lr, ip, r0, r1
    mla ip, r0, r2, ip
    mov     r3, r0, asr 0x1f
    mla ip, r3, r1, ip
    adds lr, lr, #0x0
    adc r0, ip, #0x800
    mov     r0, r0, asr 0xc
    strh r0, [sp, #0x6]
    ldrh r1, [sp, #0x6]
    mov r0, r4
    strh r1, [r5, #0x20]
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
    add sp, sp, #0xc
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
