#include "m2c.h"

extern s32 OSi_SystemCallbackInSwitchThread;
extern s32 OSi_ThreadInfo;

extern s32 func_020ce85c(void);
extern s32 OS_SelectThread(void);
extern void OS_SaveContext(s32);
extern void OS_LoadContext(s32);

// clang-format off
asm void OSi_RescheduleThread(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r0, =OSi_SystemCallbackInSwitchThread
    ldr r5, =OSi_ThreadInfo
    ldr r0, [r0, #0x4]
    cmp r0, #0x0
    ldmneia sp!, {r4, r5, r6, pc}
    ldrh r0, [r5, #0x2]
    cmp r0, #0x0
    bne L_020cd5cc
    bl func_020ce85c
    cmp r0, #0x12
    bne L_020cd5d8
L_020cd5cc:
    mov r0, #0x1
    strh r0, [r5, #0x0]
    ldmia sp!, {r4, r5, r6, pc}
L_020cd5d8:
    ldr r0, =OSi_SystemCallbackInSwitchThread
    ldr r0, [r0, #0x8]
    ldr r6, [r0, #0x0]
    bl OS_SelectThread
    mov r4, r0
    cmp r6, r4
    cmpne r4, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
    ldr r0, [r6, #0x64]
    cmp r0, #0x2
    beq L_020cd614
    mov r0, r6
    bl OS_SaveContext
    cmp r0, #0x0
    ldmneia sp!, {r4, r5, r6, pc}
L_020cd614:
    ldr r0, =OSi_SystemCallbackInSwitchThread
    ldr r2, [r0, #0x0]
    cmp r2, #0x0
    beq L_020cd630
    mov r0, r6
    mov r1, r4
    blx r2
L_020cd630:
    ldr r2, [r5, #0xc]
    cmp r2, #0x0
    beq L_020cd648
    mov r0, r6
    mov r1, r4
    blx r2
L_020cd648:
    ldr r1, =OSi_SystemCallbackInSwitchThread
    mov r0, r4
    str r4, [r1, #0x28]
    bl OS_LoadContext
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
