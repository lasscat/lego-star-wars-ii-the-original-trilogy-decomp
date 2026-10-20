#include "m2c.h"

void func_0205e80c(s32, s32, s32);
void func_020accac(s32, s32, s32, s32);
void func_020179b4(s32, s32, s32);

// clang-format off
asm void func_02051430(s32 *a0) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x68
    ldrsh r2, [r0, #0x4]
    ldrsh r1, [r0, #0x2]
    ldrsh r0, [r0, #0x0]
    mov lr, r2, lsl #0xc
    mov ip, r1, lsl #0xc
    mov r3, r0, lsl #0xc
    mov r1, #0x0
    mov r0, #0xd4
    mov r2, #0x4
    str r3, [sp, #0x14]
    str ip, [sp, #0x18]
    str lr, [sp, #0x1c]
    bl func_0205e80c
    movs r4, r0
    beq L_020514c0
    mov lr, #0x1000
    mov ip, #0x0
    add r0, sp, #0x20
    add r1, sp, #0x14
    add r2, sp, #0x0
    add r3, sp, #0x8
    str lr, [sp, #0x8]
    str lr, [sp, #0xc]
    str lr, [sp, #0x10]
    strh ip, [sp, #0x0]
    strh ip, [sp, #0x2]
    strh ip, [sp, #0x4]
    bl func_020accac
    add r3, sp, #0x20
    mov r0, r4
    mov r1, #0x200
    mov r2, #0x0
    bl func_020179b4
    mov r4, r0
L_020514c0:
    ldr r1, [r4, #0x8]
    mov r0, r4
    orr r1, r1, #0x200000
    str r1, [r4, #0x8]
    add sp, sp, #0x68
    ldmia sp!, {r4, pc}
}
// clang-format on
