#include "m2c.h"

extern u32 data_0210dd7c[];
extern u32 data_0210dc20[];
extern u32 data_0210dd54[];

void func_020bb74c(void);
void func_020bb488(s32);
void func_020bb36c(s32);
void func_020bb6b0(s32, s32);
void SND_WaitForFreeCommand(s32);
void SND_StopTimer(s32, s32, s32);
s32 SND_GetCurrentCommandTag(void);

// clang-format off
asm void func_020bb778(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r9, #0x0
    bl func_020bb74c
    ldr r10, =data_0210dd7c
    ldr r7, =data_0210dc20
    mov r8, #0xb
    mov r11, r9
    mov r6, #0x1
    mov r5, #0x4
    mov r4, #0x1c
L_020bb7a0:
    ldrb r0, [r10, #0x1]
    cmp r0, #0x3
    bne L_020bb7e8
    ldrb r1, [r10, #0x0]
    mla r0, r1, r4, r7
    ldrb r0, [r0, #0x180]
    tst r0, #0x10
    beq L_020bb7d8
    ldrb r0, [r10, #0x2]
    orr r1, r8, #0x20
    orr r9, r9, r6, lsl r0
    bl func_020bb488
    strb r5, [r10, #0x1]
    b L_020bb7e8
L_020bb7d8:
    mov r0, r8
    bl func_020bb36c
    mov r1, r11
    bl func_020bb6b0
L_020bb7e8:
    sub r10, r10, #0x1c
    subs r8, r8, #0x1
    bpl L_020bb7a0
    cmp r9, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, #0x1
    bl SND_WaitForFreeCommand
    mov r1, #0x0
    mov r0, r9
    mov r2, r1
    mov r3, r1
    bl SND_StopTimer
    bl SND_GetCurrentCommandTag
    ldr r2, =data_0210dd54
    mov r3, #0xb
    mov r1, #0x1
L_020bb828:
    tst r9, r1, lsl r3
    strne r0, [r2, #0x40]
    sub r2, r2, #0x1c
    subs r3, r3, #0x1
    bpl L_020bb828
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
