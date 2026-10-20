#include "m2c.h"

extern u32 data_0210da80[];

void func_020afcac(s32);
s32 func_020b01e0(s32);
s32 OS_DisableInterrupts(void);
void OS_RestoreInterrupts(s32);
void MB_DisconnectChild(s32);

// clang-format off
asm void func_020affbc(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r0, #0x3
    bl func_020afcac
    mov r5, #0x1
    ldr r7, =data_0210da80
    mov r4, r5
L_020affd4:
    ldrh r0, [r7, #0xa]
    tst r0, r4, lsl r5
    beq L_020b0050
    mov r0, r5
    bl func_020b01e0
    cmp r0, #0x1
    bne L_020b0050
    mvn r0, r4, lsl r5
    mov r6, r0, lsl #0x10
    bl OS_DisableInterrupts
    ldrh r1, [r7, #0xa]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0xa]
    ldrh r1, [r7, #0xc]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0xc]
    ldrh r1, [r7, #0xe]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0xe]
    ldrh r1, [r7, #0x10]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0x10]
    ldrh r1, [r7, #0x12]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0x12]
    ldrh r1, [r7, #0x14]
    and r1, r1, r6, lsr #0x10
    strh r1, [r7, #0x14]
    bl OS_RestoreInterrupts
    mov r0, r5
    bl MB_DisconnectChild
L_020b0050:
    add r0, r5, #0x1
    mov r0, r0, lsl #0x10
    mov r5, r0, lsr #0x10
    cmp r5, #0x10
    blo L_020affd4
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
