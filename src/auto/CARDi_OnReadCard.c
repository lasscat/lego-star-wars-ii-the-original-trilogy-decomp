#include "m2c.h"

extern u32 cardi_common[];
extern void MI_StopDma();
extern void OS_DisableIrqMask();
extern void OS_ResetRequestIrqMask();
extern void CARDi_ReadRomIDCore();
extern void CARDi_CheckPulledOutCore();
extern void OS_DisableInterrupts();
extern void OS_WakeupThread();
extern void OS_WakeupThreadDirect();
extern void OS_RestoreInterrupts();
extern void CARDi_SetCardDma();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARDi_OnReadCard(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    ldr     r0, =cardi_common
    ldr r0, [r0, #0x28]
    bl     MI_StopDma
    ldr     r3, =cardi_common
    ldr r0, [r3, #0x24]
    ldr r2, [r3, #0x1c]
    ldr r1, [r3, #0x20]
    subs r0, r0, #512
    str r0, [r3, #0x24]
    movne r0, #1
    add r2, r2, #512
    add r1, r1, #512
    moveq r0, #0
    str r2, [r3, #0x1c]
    str r1, [r3, #0x20]
    cmp r0, #0
    bne    L_020d58e8
    mov r0, #524288
    bl     OS_DisableIrqMask
    mov r0, #524288
    bl     OS_ResetRequestIrqMask
    ldr     r4, =cardi_common
    bl     CARDi_ReadRomIDCore
    bl     CARDi_CheckPulledOutCore
    ldr r0, [r4]
    mov r1, #0
    str r1, [r0]
    ldr r5, [r4, #0x38]
    ldr r6, [r4, #0x3c]
    bl     OS_DisableInterrupts
    ldr r1, [r4, #0x114]
    mov r7, r0
    bic r0, r1, #76
    str r0, [r4, #0x114]
    add r0, r4, #268
    bl     OS_WakeupThread
    ldr r0, [r4, #0x114]
    tst r0, #16
    beq    L_020d58cc
    add r0, r4, #68
    bl     OS_WakeupThreadDirect
L_020d58cc:
    mov r0, r7
    bl     OS_RestoreInterrupts
    cmp r5, #0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r6
    blx r5
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020d58e8:
    bl     CARDi_SetCardDma
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
