#include "m2c.h"

extern void func_02053adc();
extern void func_02053850();
extern void func_0209ec08();
extern void func_0209ecc0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209eba0(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldr r1, [r4, #0xc]
    mov r2, #0xb6
    add r0, sp, #0x4
    strh r2, [sp, #0x2]
    strh r2, [sp, #0x0]
    bl      func_02053adc
    add r0, sp, #0x4
    ldrh r3, [r0, #0x0]
    ldrh r1, [sp, #0x0]
    ldr r0, [r4, #0xc]
    sub r2, sp, #0x4
    add r1, r3, r1
    strh r1, [sp, #0x6]
    ldrh r1, [sp, #0x6]
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_02053850
    mov r0, r4
    bl      func_0209ec08
    mov r0, r4
    bl      func_0209ecc0
    add sp, sp, #0x8
    ldmia   sp!, {r4, pc}
}
// clang-format on
