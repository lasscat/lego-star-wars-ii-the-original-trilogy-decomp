#include "m2c.h"

extern s32 data_027e02a8;
extern void func_02060cd0(s32);
extern void clearDataAndInstructionCache(s32, s32);
extern void func_0201b254(s32);

// clang-format off
asm void func_0201adc4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, r5, lr}
    ldr r3, =data_027e02a8
    mov r4, r0
    ldr r0, [r3, #0x0]
    mov r5, r2
    tst r0, #0x200
    ldr r0, [r4, #0x0]
    movne r2, #0x0
    bne L_0201adfc
    ldr r0, [r0, #0x8]
    tst r0, #0x80000000
    movne r2, #0x0
    moveq r2, #0x1
L_0201adfc:
    ldr r0, [r4, #0x0]
    bl func_02060cd0
    ldr r0, [r4, #0x0]
    mov r1, r5
    bl clearDataAndInstructionCache
    ldr r1, [sp, #0x1c]
    ldr r0, [r4, #0x0]
    ldr r2, [sp, #0x20]
    str r1, [r0, #0x4c]
    ldr r0, [r4, #0x0]
    ldrb r1, [sp, #0x24]
    str r2, [r0, #0x50]
    ldr r0, [r4, #0x0]
    bl func_0201b254
    ldmia sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
