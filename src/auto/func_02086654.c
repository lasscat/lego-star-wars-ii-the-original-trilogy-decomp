#include "m2c.h"

extern u8 data_020f4910[];
extern u8 data_020f6ba8[];

extern void func_020865ac(s32, s32);
extern void func_02086600(s32, s32);

// clang-format off
asm void func_02086654(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r0
    mov r6, r1
    add r0, r7, #0x114
    and r4, r6, #0x1f
    mov r8, #0x1
    add r2, r0, #0x4400
    mov r3, r6, asr #0x5
    mvn r0, r8, lsl r4
    ldr r1, [r2, r3, lsl #0x2]
    mov r5, #0x0
    and r1, r1, r0
    orr r0, r1, r8, lsl r4
    ldr r4, =data_020f4910
    str r0, [r2, r3, lsl #0x2]
L_02086690:
    ldrb r0, [r4, r5, lsl #0x2]
    mov r1, r5, lsl #0x2
    cmp r0, #0x3
    addeq r0, r4, r1
    ldreqsh r0, [r0, #0x2]
    cmpeq r6, r0
    bne L_020866b8
    mov r0, r7
    mov r1, r5
    bl func_020865ac
L_020866b8:
    add r0, r5, #0x1
    mov r0, r0, lsl #0x10
    mov r5, r0, lsr #0x10
    cmp r5, #0xfa
    blo L_02086690
    ldr r4, =data_020f6ba8
    mov r5, #0x0
    mov r8, #0x24
L_020866d8:
    mla r1, r5, r8, r4
    ldrh r0, [r1, #0x20]
    cmp r0, #0x3
    ldreqh r0, [r1, #0x22]
    cmpeq r6, r0
    bne L_020866fc
    mov r0, r7
    mov r1, r5
    bl func_02086600
L_020866fc:
    add r0, r5, #0x1
    mov r0, r0, lsl #0x10
    mov r5, r0, lsr #0x10
    cmp r5, #0x28
    blo L_020866d8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
