#include "m2c.h"

extern void func_02067080();
extern u32 data_02104d90[];
extern void func_02086e4c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02059c04(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r1
    ldrb r1, [r5, #0x0]
    ldrb r2, [r5, #0x1]
    bl      func_02067080
    movs r4, r0
    ldmeqia   sp!, {r3, r4, r5, pc}
    ldrh r0, [r4, #0xc]
    cmp r0, #0x4
    ldmneia   sp!, {r3, r4, r5, pc}
    ldrb r1, [r5, #0x2]
    ldr     r0, =data_02104d90
    bl      func_02086e4c
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r2, #0x0
    mov r0, r4
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
