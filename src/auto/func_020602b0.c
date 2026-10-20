#include "m2c.h"

void func_02060710(void);
void func_02060800(void);

// clang-format off
asm void func_020602b0(s32 *obj, u16 val, s32 flag, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, lr}
    ldrh r3, [sp, #0xc]
    add r1, r0, #0xc00
    cmp r2, #0x0
    strh r3, [r1, #0x26]
    bne L_020602dc
    bl func_02060710
    ldmia sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
L_020602dc:
    bl func_02060800
    ldmia sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
