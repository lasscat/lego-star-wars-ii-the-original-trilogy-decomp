#include "m2c.h"

extern s32 func_0205e80c(s32, s32, s32);
extern s32 func_0201cba8(s32, s32, s32, s32, s32);

// clang-format off
asm s32 func_0205151c(s32 a0) {
    stmdb sp!, {r4, r5, lr}
    sub sp, sp, #0x2c
    mov r4, r0
    ldrsh r2, [r4, #0x4]
    ldrsh r1, [r4, #0x2]
    ldrsh r0, [r4, #0x0]
    mov r2, r2, lsl #0xc
    mov r1, r1, lsl #0xc
    mov r0, r0, lsl #0xc
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    str r2, [sp, #0x28]
    ldrh r2, [r4, #0xc]
    ldrh r1, [r4, #0xa]
    ldrh r0, [r4, #0x8]
    mov lr, r2, lsl #0xc
    mov ip, r1, lsl #0xc
    mov r3, r0, lsl #0xc
    mov r0, #0x1d8
    mov r1, #0x0
    mov r2, #0x4
    str r3, [sp, #0x14]
    str ip, [sp, #0x18]
    str lr, [sp, #0x1c]
    bl func_0205e80c
    movs r5, r0
    beq L_020515c4
    ldrb r1, [r4, #0x10]
    mov r3, #0x0
    add r2, sp, #0x14
    str r1, [sp, #0x0]
    ldrb ip, [r4, #0x11]
    mov r1, #0x800
    str ip, [sp, #0x4]
    ldrb ip, [r4, #0x12]
    str ip, [sp, #0x8]
    ldrb ip, [r4, #0x13]
    str ip, [sp, #0xc]
    str r3, [sp, #0x10]
    ldrb r3, [r4, #0xe]
    bl func_0201cba8
    mov r5, r0
L_020515c4:
    mov r0, r5
    ldr r2, [r0, #0x0]
    add r1, sp, #0x20
    ldr r2, [r2, #0x38]
    blx r2
    mov r0, r5
    add sp, sp, #0x2c
    ldmia sp!, {r4, r5, pc}
}
// clang-format on
