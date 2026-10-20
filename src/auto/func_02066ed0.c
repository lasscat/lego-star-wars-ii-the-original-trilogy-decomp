#include "m2c.h"

void func_02067118(void);
s32 func_020e4600(s32, s32, s32, s32, s32);
void func_02067154(s32, s32, s32, s32);

// clang-format off
asm void func_02066ed0(s32 *obj, s32 *arg) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x8
    mov r7, r0
    add r0, r7, #0xc00
    ldrh r0, [r0, #0x18]
    mov r6, r1
    cmp r0, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r0, [r7, #0xc]
    cmp r0, #0x0
    beq L_02066f1c
    ldr r1, =func_02067118
    mov r3, #0x0
    str r1, [sp, #0x0]
    mov r1, #0x2
    mov r2, #0x28
    str r3, [sp, #0x4]
    bl func_020e4600
L_02066f1c:
    str r0, [r7, #0x4]
    ldr r0, [r7, #0xc]
    add r9, r7, #0xc00
    add r0, r0, #0x58
    str r0, [r7, #0xc]
    ldrh r0, [r9, #0x18]
    mov r5, #0x0
    mov r4, r5
    cmp r0, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r8, #0x28
L_02066f4c:
    cmp r4, #0x0
    ldrneh r0, [r9, #0x14]
    cmpne r4, r0
    bne L_02066f7c
    mul r0, r5, r8
    ldr ip, [r7, #0x4]
    mov r1, r7
    mov r2, r6
    mov r3, r4
    add r0, ip, r0
    add r5, r5, #0x1
    bl func_02067154
L_02066f7c:
    ldrh r1, [r6, #0x0]
    ldrh r0, [r9, #0x18]
    add r4, r4, #0x1
    add r6, r6, r1
    cmp r4, r0
    blo L_02066f4c
    add sp, sp, #0x8
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
