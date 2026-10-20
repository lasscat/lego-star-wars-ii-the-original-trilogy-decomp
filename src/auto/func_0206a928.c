#include "m2c.h"

extern void func_020aaeb4();
extern void func_020ad13c();
extern void func_020a9890();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206a928(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    bl      func_020aaeb4
    mov r1, r0
    ldr r2, [r4, #0x34]
    add r0, sp, #0x0
    add r1, r1, #0x4c
    bl      func_020ad13c
    bl      func_020aaeb4
    ldrh r1, [r4, #0x82]
    sub r2, sp, #0x4
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_020a9890
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
