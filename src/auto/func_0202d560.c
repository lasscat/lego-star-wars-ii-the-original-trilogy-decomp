#include "m2c.h"

extern u8 data_020ff7de[];
extern s16 data_020f6a6c[];
extern s16 data_020f6a70[];
extern s16 data_020f6a72[];
extern s16 data_020f6a6e[];

extern void func_0202d5f0(s32);

// clang-format off
asm void func_0202d560(s32 a0) {
    stmdb sp!, {r3, lr}
    ldrb ip, [r0, #0x1]
    ldr r2, =data_020ff7de
    ldr r3, =data_020f6a6c
    ldrb ip, [r2, ip, lsl #0x3]
    ldrsh lr, [r0, #0x4]
    mov r2, #0x0
    mov ip, ip, lsl #0x4
    ldrsh r3, [r3, ip]
    cmp lr, r3
    ble L_0202d5c8
    ldr r2, =data_020f6a70
    ldrsh r2, [r2, ip]
    cmp lr, r2
    ble L_0202d5b4
    ldr r2, =data_020f6a72
    ldrsh r2, [r2, ip]
    cmp lr, r2
    strgth r2, [r0, #0x4]
    mov r2, #0x3
    b L_0202d5c8
L_0202d5b4:
    ldr r2, =data_020f6a6e
    ldrsh r2, [r2, ip]
    cmp lr, r2
    movgt r2, #0x2
    movle r2, #0x1
L_0202d5c8:
    ldrb r3, [r0, #0x2]
    cmp r2, r3
    ldmeqia sp!, {r3, pc}
    bl func_0202d5f0
    ldmia sp!, {r3, pc}
}
// clang-format on
