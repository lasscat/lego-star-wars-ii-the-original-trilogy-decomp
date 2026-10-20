#include "m2c.h"

extern void func_02047b94();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02047b38(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov r1, #0x1
    bl      func_02047b94
    ldrb r0, [r4, #0xe]
    cmp r0, #0x0
    moveq r0, #0x0
    addeq sp, sp, #0x4
    streqb r0, [r4, #0xd]
    ldmeqia   sp!, {r3, r4, pc}
    mov r0, #0x5
    strb r0, [r4, #0xd]
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r1, #0x4
    ldr ip, [r0, #0x0]
    mov r3, #0x1
    ldr ip, [ip, #0x24]
    blx      ip
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
