#include "m2c.h"

extern void func_0202cb68();
extern void func_0202cb7c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020329a4(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r2, [r4, #0x4]
    mov r1, #0x0
    ldr r0, [r2, #0x8]
    mov r3, r1
    orr r0, r0, #0x200
    str r0, [r2, #0x8]
    str r1, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r2, #0x1
    ldr ip, [r0, #0x0]
    ldr ip, [ip, #0x24]
    blx      ip
    ldrb r0, [r4, #0x1c]
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    ldr r0, [r4, #0x4]
    add r0, r0, #0x5e0
    bl      func_0202cb68
    str r0, [r4, #0x10]
    ldr r0, [r4, #0x4]
    add r0, r0, #0x5e0
    bl      func_0202cb7c
    str r0, [r4, #0x14]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
