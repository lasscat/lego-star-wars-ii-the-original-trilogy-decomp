#include "m2c.h"

extern void func_020531d8();
extern void func_02053964();
extern void func_02053010();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02053c98(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r6, r1
    mov r5, r2
    bl      func_020531d8
    mov r4, r0
    mov r0, r7
    bl      func_02053964
    ldr r1, [r7, #0x0]
    mov r2, r6
    str r1, [sp, #0x0]
    ldrh r1, [r4, #0x0]
    sub ip, sp, #0x4
    mov r3, r5
    strh r1, [ip, #0x0]
    mov r1, r0
    ldr r0, [ip, #0x0]
    bl      func_02053010
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
