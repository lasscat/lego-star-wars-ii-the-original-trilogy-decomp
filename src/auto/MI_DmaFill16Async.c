#include "m2c.h"

void MI_WaitDma(void);
void OSi_EnterDmaCallback(s32, s32, s32);
s32 OS_DisableInterrupts(void);
void MIi_DmaSetParams_noInt(s32, s32, s32);
void OS_RestoreInterrupts(s32);

// clang-format off
asm void MI_DmaFill16Async(s32 arg0, s32 arg1, s32 arg2, s32 arg3, ...) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    movs r4, r3
    mov r7, r0
    mov r6, r1
    mov r5, r2
    ldr r8, [sp, #0x18]
    bne L_020cee08
    cmp r8, #0x0
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    ldr r0, [sp, #0x1c]
    blx r8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_020cee08:
    bl MI_WaitDma
    cmp r8, #0x0
    beq L_020cee60
    ldr r2, [sp, #0x1c]
    mov r0, r7
    mov r1, r8
    bl OSi_EnterDmaCallback
    bl OS_DisableInterrupts
    mov r3, r4, lsr #0x1
    mov r2, r7, lsl #0x2
    add r1, r2, #0xe0
    add r2, r2, #0x4000000
    str r5, [r2, #0xe0]
    mov r4, r0
    mov r0, r7
    mov r2, r6
    add r1, r1, #0x4000000
    orr r3, r3, #0xc1000000
    bl MIi_DmaSetParams_noInt
    mov r0, r4
    bl OS_RestoreInterrupts
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_020cee60:
    bl OS_DisableInterrupts
    mov r2, r7, lsl #0x2
    add r1, r2, #0xe0
    mov r3, r4, lsr #0x1
    mov r4, r0
    add ip, r2, #0x4000000
    mov r0, r7
    mov r2, r6
    add r1, r1, #0x4000000
    orr r3, r3, #0x81000000
    str r5, [ip, #0xe0]
    bl MIi_DmaSetParams_noInt
    mov r0, r4
    bl OS_RestoreInterrupts
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
