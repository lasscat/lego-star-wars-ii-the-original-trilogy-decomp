#include "m2c.h"

extern void func_020aaeb4();
extern void func_020a98e4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057c94(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrh r0, [r1, #0x0]
    mov     r0, r0, lsl 0xc
    str r0, [sp, #0x0]
    bl      func_020aaeb4
    add r1, sp, #0x0
    ldr r1, [r1, #0x0]
    bl      func_020a98e4
    ldmia   sp!, {r3, pc}
}
// clang-format on
