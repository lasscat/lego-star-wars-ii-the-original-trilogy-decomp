#include "m2c.h"

extern void func_02067080();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205698c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r1
    ldrb r1, [r4, #0x0]
    ldrb r2, [r4, #0x1]
    bl      func_02067080
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    mov r1, #0x0
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    ldrb r1, [r4, #0x2]
    mov r2, #0x1
    ldr ip, [ip, #0x24]
    mov r3, r2
    blx      ip
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
