#include "m2c.h"

extern void func_02067080();
extern u32 data_021090d4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02056190(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r1
    ldrb r1, [r4, #0x1]
    ldrb r2, [r4, #0x2]
    bl      func_02067080
    cmp r0, #0x0
    ldmeqia   sp!, {r4, pc}
    ldrb r2, [r4, #0x0]
    ldr     r3, =data_021090d4
    mov r1, #0xc
    mla r1, r2, r1, r3
    add r2, r0, #0xb0
    cmp r1, r2
    ldmeqia   sp!, {r4, pc}
    ldr r0, [r2, #0x0]
    str r0, [r1, #0x0]
    ldr r0, [r2, #0x4]
    str r0, [r1, #0x4]
    ldr r0, [r2, #0x8]
    str r0, [r1, #0x8]
    ldmia   sp!, {r4, pc}
}
// clang-format on
