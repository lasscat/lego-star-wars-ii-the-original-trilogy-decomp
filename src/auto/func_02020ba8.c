#include "m2c.h"

extern void func_02011384();
extern u32 data_020fd608[];
extern void func_02020e4c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02020ba8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r0
    mov r5, r1
    bl      func_02011384
    ldr     r1, =data_020fd608
    ldr     r0, =0x13f
    str r1, [r4, #0x0]
    mov r1, #0x0
    str r1, [r4, #0x218]
    cmp r5, r0
    mov r2, #0x1
    str r1, [r4, #0x21c]
    moveq r0, #0x7
    streqb r0, [r4, #0x1bc]
    strneb r1, [r4, #0x1bc]
    mov r1, #0x0
    str r1, [sp, #0x0]
    mov r0, r4
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x24]
    mov r1, #0x8a
    blx      ip
    mov r0, #0x1b
    str r0, [r4, #0x84]
    ldr     r1, =func_02020e4c
    mov r0, r4
    str r1, [r4, #0x18]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
