#include "m2c.h"

extern void func_0205357c();
extern void func_020535a8();
extern void func_020536a8();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205353c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    ldrh r1, [sp, #0xc]
    sub r2, sp, #0x4
    mov r4, r0
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_0205357c
    mov r0, r4
    bl      func_020535a8
    mov r0, r4
    mov r1, #0x1
    bl      func_020536a8
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
