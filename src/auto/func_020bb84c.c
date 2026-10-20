#include "m2c.h"

extern M2C_UNK data_0210dd7c[];
extern M2C_UNK data_0210dd98[];

s32 func_020bb388(s32, s32);
void func_020bb3f8(s32, s32);
void SND_WaitForFreeCommand(s32);
void func_020bada8(s32, s32);
void func_020baef0(s32);
void SND_StartTimer(s32, s32, s32, s32);
s32 SND_GetCurrentCommandTag(void);

// clang-format off
asm void func_020bb84c(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    ldr r9, =data_0210dd7c
    ldr r6, =data_0210dd98
    mov r7, #0xb
    mov r5, #0x3
    mov r11, #0x1
    mov r4, #0x0
L_020bb868:
    ldrb r0, [r9, #0x1]
    cmp r0, #0x4
    bne L_020bb900
    ldrb r1, [r9, #0x0]
    mov r0, #0x1c
    orr r10, r7, #0x20
    mla r8, r1, r0, r6
    ldrb r0, [r8, #0x8]
    tst r0, #0x10
    ldreqb r0, [r9, #0x3]
    movne r1, #0xff
    addeq r1, r0, #0xbe
    mov r0, r10
    strb r5, [r9, #0x1]
    bl func_020bb388
    strb r0, [r9, #0x2]
    and r0, r0, #0xff
    cmp r0, #0xff
    moveq r0, #0x1
    streqb r0, [r9, #0x1]
    beq L_020bb900
    mov r1, r10
    bl func_020bb3f8
    mov r0, #0x4
    bl SND_WaitForFreeCommand
    ldrb r0, [r9, #0x2]
    mov r1, r8
    bl func_020bada8
    mov r0, r9
    bl func_020baef0
    ldrb r0, [r9, #0x2]
    mov r1, r4
    mov r2, r4
    mov r0, r11, lsl r0
    mov r3, r4
    bl SND_StartTimer
    bl SND_GetCurrentCommandTag
    str r0, [r9, #0x18]
L_020bb900:
    sub r9, r9, #0x1c
    subs r7, r7, #0x1
    bpl L_020bb868
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
