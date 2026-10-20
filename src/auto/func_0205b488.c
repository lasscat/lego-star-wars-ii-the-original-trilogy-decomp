#include "m2c.h"

extern void func_0205b5d8(s32 *);
extern s32 func_0205b850(s32);
extern void func_0205e84c(s32);

// clang-format off
asm void func_0205b488(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, r5, r6, lr}
    mov r5, r1
    ldr r4, [sp, #0x18]
    ldr r1, [r5, #0x8]
    mov r6, r0
    cmp r4, r1
    bne L_0205b4b8
    add r0, sp, #0x18
    bl func_0205b5d8
    ldr r0, [sp, #0x18]
    str r0, [r5, #0x8]
L_0205b4b8:
    ldr r1, [r5, #0x4]
    mov r0, r4
    bl func_0205b850
    str r0, [r6, #0x0]
    mov r0, r4
    bl func_0205e84c
    ldr r0, [r5, #0x0]
    sub r0, r0, #0x1
    str r0, [r5, #0x0]
    ldmia sp!, {r4, r5, r6, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
