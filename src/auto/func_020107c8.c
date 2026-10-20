#include "m2c.h"

extern u32 data_020eb7b8[];
extern void func_02010c0c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020107c8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4
    mov r6, r0
    add r0, r6, #0x100
    ldrh r0, [r0, #0x80]
    ldr     ip, =data_020eb7b8
    mov r5, r2
    add r0, ip, r0, lsl #0x3
    mov r4, r3
    bl      func_02010c0c
    movs r1, r0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    ldrb r3, [sp, #0x18]
    mov r0, r6
    mov r2, r5
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r3, r4
    ldr ip, [ip, #0x28]
    blx      ip
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
