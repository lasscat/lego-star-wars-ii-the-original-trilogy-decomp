#include "m2c.h"

extern void func_02029428();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202817c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    movs r5, r0
    mov r4, r1
    cmpne r4, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r0, r4
    bl      func_02029428
    mov r2, #0x0
    mov r0, r4
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x29
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r2, #0x0
    mov r0, r5
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0xf
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
