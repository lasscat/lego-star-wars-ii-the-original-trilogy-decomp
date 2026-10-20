#include "m2c.h"

extern s32 func_0200ec08(u16, u16, u16, s32);
extern void func_02018200(s32, s32, s32);

// clang-format off
asm s32 func_0200ed14(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, r5, lr}
    ldr r1, [sp, #0x1c]
    mov r5, r0
    str r1, [sp, #0x0]
    ldrh r1, [r5, #0xca]
    sub lr, sp, #0x4
    ldrh ip, [sp, #0x14]
    strh r1, [lr, #0x0]
    ldr r1, [lr, #0x0]
    add r2, sp, #0x18
    strh ip, [lr, #0x0]
    ldr r3, [r2, #0x0]
    ldr r2, [lr, #0x0]
    bl func_0200ec08
    movs r4, r0
    beq L_0200ed68
    mov r0, r5
    mov r1, r4
    mov r2, #0x0
    bl func_02018200
L_0200ed68:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
