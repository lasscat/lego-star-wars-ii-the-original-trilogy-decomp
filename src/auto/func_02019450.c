#include "m2c.h"

extern void func_02018e74(s32 a0);
extern void func_02018cf4(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02019450(s32 a0, s32 a1) {
    stmdb sp!, {r3, lr}
    ldrb r2, [r0, #0x1c1]
    cmp r2, #0x0
    ldmneia sp!, {r3, pc}
    ldr r2, [r0, #0x8]
    and r2, r2, #0x2
    cmp r2, #0x2
    ldmeqia sp!, {r3, pc}
    ldr r1, [r1, #0x0]
    cmp r1, #0x0
    ldmeqia sp!, {r3, pc}
    ldrb r2, [r0, #0x1c2]
    cmp r2, #0x0
    beq L_02019490
    bl func_02018e74
    ldmia sp!, {r3, pc}
L_02019490:
    bl func_02018cf4
    ldmia sp!, {r3, pc}
}
// clang-format on
