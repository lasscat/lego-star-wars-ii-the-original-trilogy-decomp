#include "m2c.h"

void func_02067af0(void);
s32 func_020e4600(s32, s32, s32, s32, s32);
void func_02067b00(s32, s32, s32);

// clang-format off
asm void func_02067440(s32 *obj, s32 *a1, s32 *a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x8
    mov r8, r0
    mov r5, r1
    ldrh r1, [r8, #0x1c]
    mov r4, r2
    cmp r1, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    ldr r0, [r5, #0xc]
    cmp r0, #0x0
    beq L_02067488
    ldr r2, =func_02067af0
    mov r3, #0x0
    str r2, [sp, #0x0]
    mov r2, #0x8
    str r3, [sp, #0x4]
    bl func_020e4600
L_02067488:
    str r0, [r8, #0xc]
    ldrh r0, [r8, #0x1c]
    ldr r1, [r5, #0xc]
    add r2, r4, #0x10
    mov r0, r0, lsl #0x3
    add r0, r0, #0x8
    add r0, r1, r0
    str r0, [r5, #0xc]
    ldrh r1, [r4, #0xa]
    ldrh r0, [r8, #0x1c]
    mov r6, #0x0
    add r4, r2, r1
    cmp r0, #0x0
    add r5, r4, r0, lsl #0x1
    addls sp, sp, #0x8
    ldmlsia sp!, {r4, r5, r6, r7, r8, pc}
    mov r7, r6
L_020674cc:
    mov r0, r6, lsl #0x1
    ldrh r2, [r4, r0]
    ldr r0, [r8, #0xc]
    ldrb r1, [r5, r6]
    add r0, r0, r7
    add r2, r4, r2
    bl func_02067b00
    ldrh r0, [r8, #0x1c]
    add r6, r6, #0x1
    add r7, r7, #0x8
    cmp r6, r0
    blo L_020674cc
    add sp, sp, #0x8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
