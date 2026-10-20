#include "m2c.h"

extern void func_020531d8();
extern void func_02053964();
extern void func_020530b0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205365c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4
    mov r6, r0
    mov r5, r1
    bl      func_020531d8
    mov r4, r0
    mov r0, r6
    bl      func_02053964
    str r0, [sp, #0x0]
    ldrh r0, [r4, #0x0]
    ldr r2, [r6, #0x0]
    sub r1, sp, #0x4
    strh r0, [r1, #0x0]
    ldr r3, [r1, #0x0]
    mov r0, r5
    mov r1, #0x0
    bl      func_020530b0
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
