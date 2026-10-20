#include "m2c.h"

extern u32 data_0210dd98[];
extern u32 data_0210db84[];
extern u32 data_0210dc34[];

extern void SND_WaitForFreeCommand(s32 a0, s32 a1);
extern void SND_SetChannelVolume(s32 a0, s32 a1, s32 a2);
extern void SND_SetChannelPan(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020baef0(s32 a0) {
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    ldrb r1, [r7, #0x0]
    ldr r2, =data_0210dd98
    mov r0, #0x1c
    mla r6, r1, r0, r2
    ldr r0, =data_0210db84
    ldrb r1, [r6, #0x7]
    ldrb r0, [r0, #0xc1]
    ldrb r3, [r7, #0x3]
    ldrb r2, [r7, #0x5]
    smulbb r0, r1, r0
    sub r1, r3, r2
    mul r0, r1, r0
    mov r4, r0, asr #0xc
    cmp r4, #0xa
    bge L_020baf3c
    cmp r4, #0x0
    movgt r4, #0xa
L_020baf3c:
    ldrb r1, [r7, #0x4]
    mov r0, #0x2
    rsb r1, r1, r1, lsl #0x7
    mov r5, r1, asr #0x6
    bl SND_WaitForFreeCommand
    ldrb r0, [r7, #0x2]
    mov r2, #0x1
    mov r1, r4
    mov r0, r2, lsl r0
    mov r2, #0x0
    bl SND_SetChannelVolume
    ldrb r0, [r7, #0x2]
    mov r2, #0x1
    mov r1, r5
    mov r0, r2, lsl r0
    bl SND_SetChannelPan
    ldrb r0, [r6, #0x8]
    ldrb r1, [r7, #0x2]
    tst r0, #0x10
    movne r2, #0xff
    ldr r0, =data_0210dc34
    addeq r2, r4, #0x60
    strb r2, [r0, r1]
    ldrb r0, [r7, #0x6]
    bic r0, r0, #0x1
    strb r0, [r7, #0x6]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
