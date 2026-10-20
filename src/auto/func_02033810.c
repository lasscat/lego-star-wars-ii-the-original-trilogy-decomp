#include "m2c.h"

extern M2C_UNK data_021027f8[];
extern M2C_UNK data_0210930c[];

s32 func_0200aef8(s32, s32, s32, s32, s32, s32);

// clang-format off
asm s32 func_02033810(s32 *obj) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x10
    mov r8, r0
    ldr r0, [r8, #0x4]
    ldrh r0, [r0, #0xc]
    cmp r0, #0x2
    bne L_020338a8
    ldr r9, =data_021027f8
    mov r7, #0x0
    ldrb r0, [r9, #0x29]
    cmp r0, #0x0
    bls L_020338a8
    ldr r6, =data_0210930c
    mov r5, #0x1e000
    add r4, sp, #0x4
L_0203384c:
    add r0, r6, r7, lsl #0x2
    ldr r3, [r0, #0x4c]
    mov r1, r4
    ldr r0, [r3, #0xb0]
    mov r2, r5
    str r0, [sp, #0x4]
    ldr r0, [r3, #0xb4]
    str r5, [sp, #0x0]
    str r0, [sp, #0x8]
    ldr r0, [r3, #0xb8]
    str r0, [sp, #0xc]
    ldr r0, [r8, #0x4]
    add r0, r0, #0xb0
    bl func_0200aef8
    cmp r0, #0x0
    addne sp, sp, #0x10
    movne r0, #0x1
    ldmneia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldrb r0, [r9, #0x29]
    add r1, r7, #0x1
    and r7, r1, #0xff
    cmp r7, r0
    blo L_0203384c
L_020338a8:
    mov r0, #0x0
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
