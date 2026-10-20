#include "m2c.h"

extern void func_02060710(void);
extern void func_02060800(void);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020602ec(s32 a0, u16 a1, s32 a2) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, lr}
    ldrh r3, [sp, #0xc]
    add r1, r0, #0xc00
    cmp r2, #0x0
    strh r3, [r1, #0x28]
    bne L_02060318
    bl func_02060710
    ldmia sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
L_02060318:
    bl func_02060800
    ldmia sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
