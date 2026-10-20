#include "m2c.h"

extern void func_020290e0();
extern void func_02029120();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202915c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov r2, r1
    add r0, sp, #0x0
    mov r1, r4
    bl      func_020290e0
    ldrh r1, [sp, #0x0]
    sub r2, sp, #0x4
    mov r0, r4
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_02029120
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
