#include "m2c.h"

extern M2C_UNK data_0210da80[];

s32 func_020d89bc(s32, s32);
s32 OS_DisableInterrupts(void);
void OS_RestoreInterrupts(s32);
void MB_DisconnectChild(s32);

// clang-format off
asm void func_020aff04(s32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r1, #0x2
    mov r4, r0
    bl func_020d89bc
    cmp r0, #0x0
    bne L_020aff88
    mov r0, #0x1
    mvn r0, r0, lsl r4
    mov r5, r0, lsl #0x10
    bl OS_DisableInterrupts
    ldr r1, =data_0210da80
    ldrh r2, [r1, #0xa]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0xa]
    ldrh r2, [r1, #0xc]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0xc]
    ldrh r2, [r1, #0xe]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0xe]
    ldrh r2, [r1, #0x10]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0x10]
    ldrh r2, [r1, #0x12]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0x12]
    ldrh r2, [r1, #0x14]
    and r2, r2, r5, lsr #0x10
    strh r2, [r1, #0x14]
    bl OS_RestoreInterrupts
    mov r0, r4
    bl MB_DisconnectChild
    ldmia sp!, {r3, r4, r5, pc}
L_020aff88:
    bl OS_DisableInterrupts
    ldr r1, =data_0210da80
    mov r5, #0x1
    ldrh r3, [r1, #0xe]
    mvn r2, r5, lsl r4
    and r2, r3, r2
    strh r2, [r1, #0xe]
    ldrh r2, [r1, #0x10]
    orr r2, r2, r5, lsl r4
    strh r2, [r1, #0x10]
    bl OS_RestoreInterrupts
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
