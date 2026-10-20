#include "m2c.h"

void func_02074c7c(s32, s32, s32);

// clang-format off
asm void func_02075540(s32 *arg0, s32 arg1, s32 arg2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    ldr r0, [r9, #0x0]
    mov r8, r1
    ldr r5, [r0, r8, lsl #0x2]
    mov r7, r2
    ldrb r0, [r5, #0x0]
    mov r6, #0x0
    cmp r0, #0x0
    ldmleia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r4, r6
L_0207556c:
    mov r0, r5
    mov r1, r6
    mov r2, r7
    bl func_02074c7c
    add r0, r5, r6, lsl #0x1
    ldrb r0, [r0, #0x1]
    ldr r2, [r9, #0x0]
    mov r1, r4
    ldr r0, [r2, r0, lsl #0x2]
    ldrb r3, [r0, #0x0]
    cmp r3, #0x0
    ble L_020755c4
L_0207559c:
    add r2, r0, r1, lsl #0x1
    ldrb r2, [r2, #0x1]
    cmp r8, r2
    bne L_020755b8
    mov r2, r7
    bl func_02074c7c
    b L_020755c4
L_020755b8:
    add r1, r1, #0x1
    cmp r1, r3
    blt L_0207559c
L_020755c4:
    ldrb r0, [r5, #0x0]
    add r6, r6, #0x1
    cmp r6, r0
    blt L_0207556c
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
