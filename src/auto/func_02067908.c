#include "m2c.h"

extern u32 data_0210930c[];

void func_020aaeb4(s32, s32, s32);
void func_020aa890(s32, s32);
void func_02096748(s32, s32, s32);

// clang-format off
asm void func_02067908(s32 *arg0, s32 arg1) {
    stmdb sp!, {lr}
    sub sp, sp, #0xc
    ldr r2, [r0, #0x0]
    sub ip, r1, #0x1
    add r1, r2, ip, lsl #0x3
    ldr r3, [r1, #0x4]
    ldrb r1, [r3, #0x6]
    cmp r1, #0x11
    bne L_02067964
    ldrsh r2, [r3, #0x4]
    ldrsh r1, [r3, #0x2]
    ldrsh r0, [r3, #0x0]
    mov r2, r2, lsl #0xc
    mov r1, r1, lsl #0xc
    mov r0, r0, lsl #0xc
    str r0, [sp, #0x0]
    str r1, [sp, #0x4]
    str r2, [sp, #0x8]
    bl func_020aaeb4
    add r1, sp, #0x0
    bl func_020aa890
    add sp, sp, #0xc
    ldmia sp!, {pc}
L_02067964:
    cmp r1, #0x9
    bne L_02067984
    ldrb r1, [r0, #0x4]
    ldr r0, =data_0210930c
    and r2, ip, #0xff
    bl func_02096748
    add sp, sp, #0xc
    ldmia sp!, {pc}
L_02067984:
    ldr r3, [r2, ip, lsl #0x3]
    cmp r3, #0x0
    addeq sp, sp, #0xc
    ldmeqia sp!, {pc}
    ldr r2, [r3, #0x8]
    mov r1, #0x0
    orr r2, r2, #0x2
    str r2, [r3, #0x8]
    ldr r0, [r0, #0x0]
    str r1, [r0, ip, lsl #0x3]
    add sp, sp, #0xc
    ldmia sp!, {pc}
}
// clang-format on
