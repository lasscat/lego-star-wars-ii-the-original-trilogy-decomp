#include "m2c.h"

extern M2C_UNK data_020ff9a0[];

void func_0208fa54(s32);
void func_02090918(s32);
void func_020901d0(s32);
s32 func_020104d0(s32);
void func_01ffad38(s32, s32, s32);
void func_020105fc(s32);

// clang-format off
asm void func_0208fb24(s32 *obj) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    bl func_0208fa54
    mov r0, r8
    bl func_02090918
    ldrb r0, [r8, #0x478]
    cmp r0, #0x0
    beq L_0208fb4c
    mov r0, r8
    bl func_020901d0
L_0208fb4c:
    ldr r0, [r8, #0x3c8]
    mov r6, #0x0
    cmp r0, #0x0
    ldmlsia sp!, {r4, r5, r6, r7, r8, pc}
    ldr r5, =data_020ff9a0
    mov r7, r8
    mov r4, r6
L_0208fb68:
    ldr r0, [r7, #0x0]
    ldr r1, [r0, #0x8]
    and r1, r1, #0x1
    cmp r1, #0x1
    bne L_0208fbbc
    bl func_020104d0
    ldr r3, [r7, #0x0]
    add r0, r3, #0x100
    ldrh r0, [r0, #0xa8]
    tst r0, #0x40
    beq L_0208fba4
    ldr r1, [r5, #0x0]
    mov r2, r4
    add r0, r3, #0xd4
    bl func_01ffad38
L_0208fba4:
    ldr r0, [r7, #0x0]
    add r1, r0, #0x100
    ldrh r1, [r1, #0xa8]
    tst r1, #0x4
    beq L_0208fbbc
    bl func_020105fc
L_0208fbbc:
    ldr r0, [r8, #0x3c8]
    add r6, r6, #0x1
    cmp r6, r0
    add r7, r7, #0x24
    blo L_0208fb68
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
