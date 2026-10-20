#include "m2c.h"

extern M2C_UNK data_020fe77c[];
extern M2C_UNK data_020fed00[];
extern M2C_UNK data_020ee240[];
extern M2C_UNK data_020ee238[];

void func_0201ad50(s32, s32, s32, s32, s32, s32, s32);

// clang-format off
asm void func_02075d00(s32 *obj, s32 arg1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x14
    ldr r2, =data_020fe77c
    mov r10, r0
    str r2, [r10, #0x0]
    mov r7, #0x0
    str r1, [r10, #0x4]
    ldr r0, =data_020fed00
    strh r7, [r10, #0x8]
    str r0, [r10, #0x0]
    str r7, [r10, #0x1c]
    str r7, [r10, #0x20]
    ldr r8, =data_020ee240
    ldr r5, =data_020ee238
    mov r9, r7
    strb r7, [r10, #0x24]
    add r4, r10, #0xc
    mov r11, r7
L_02075d48:
    add r0, r5, r7, lsl #0x1
    ldrb r1, [r0, #0x1]
    ldrb r0, [r5, r7, lsl #0x1]
    mov r2, r8
    mov r6, r1, lsl #0xc
    stmia sp, {r6, r11}
    mov r3, r0, lsl #0xc
    mov ip, #0x1
    add r0, r4, r9
    add r1, r7, #0xc
    str r3, [sp, #0x10]
    str ip, [sp, #0x8]
    bl func_0201ad50
    add r7, r7, #0x1
    cmp r7, #0x4
    add r8, r8, #0x6
    add r9, r9, #0x4
    blt L_02075d48
    mov r0, r10
    str r6, [sp, #0xc]
    add sp, sp, #0x14
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
