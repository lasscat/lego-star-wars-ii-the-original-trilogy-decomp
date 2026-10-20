#include "m2c.h"

extern u32 data_020eb7b8[];
extern void func_02010c0c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200636c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldrb r0, [r4, #0x6f3]
    cmp r0, #0x0
    addne r0, r4, #0x100
    ldrneh r2, [r0, #0x80]
    cmpne r2, #0x5
    cmpne r2, #0xc
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    ldr     r0, =data_020eb7b8
    mov r1, #0x78
    add r0, r0, r2, lsl #0x3
    bl      func_02010c0c
    mov r2, #0x0
    mov r1, r0
    str r2, [sp, #0x0]
    add r0, r4, #0xd4
    ldr ip, [r0, #0x0]
    mov r3, #0x1
    ldr ip, [ip, #0x8]
    blx      ip
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
