#include "m2c.h"

extern u32 cardi_common[];
extern void OSi_ReferSymbol();
extern void OS_Terminate();
extern void CARD_CheckEnabled();
extern void OS_DisableInterrupts();
extern void OS_SleepThread();
extern void OS_RestoreInterrupts();
extern void CARDi_IdentifyBackupCore();
extern u32 OSi_ThreadInfo[];
extern void CARDi_Request();
extern void OS_WakeupThread();
extern void OS_WakeupThreadDirect();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARD_IdentifyBackup(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    ldr     r0, =0x2000ba8
    ldr     r4, =cardi_common
    bl     OSi_ReferSymbol
    cmp r6, #0
    bne    L_020d55cc
    bl     OS_Terminate
L_020d55cc:
    bl     CARD_CheckEnabled
    bl     OS_DisableInterrupts
    ldr r1, [r4, #0x114]
    mov r5, r0
    tst r1, #4
    beq    L_020d55f8
L_020d55e4:
    add r0, r4, #268
    bl     OS_SleepThread
    ldr r0, [r4, #0x114]
    tst r0, #4
    bne    L_020d55e4
L_020d55f8:
    ldr r0, [r4, #0x114]
    mov r1, #0
    orr r2, r0, #4
    mov r0, r5
    str r2, [r4, #0x114]
    str r1, [r4, #0x38]
    str r1, [r4, #0x3c]
    bl     OS_RestoreInterrupts
    mov r0, r6
    bl     CARDi_IdentifyBackupCore
    ldr     r0, =OSi_ThreadInfo
    ldr     r1, =cardi_common
    ldr r2, [r0, #4]
    mov r0, r4
    str r2, [r1, #0x104]
    mov r1, #2
    mov r2, #1
    bl     CARDi_Request
    ldr r0, [r4]
    mov r1, #0
    str r1, [r0, #0xc]
    ldr r0, [r4]
    add r1, r4, #288
    str r1, [r0, #0x10]
    ldr r1, [r4]
    mov r2, #1
    mov r0, r4
    str r2, [r1, #0x14]
    mov r1, #6
    bl     CARDi_Request
    ldr r7, [r4, #0x38]
    ldr r6, [r4, #0x3c]
    bl     OS_DisableInterrupts
    mov r5, r0
    ldr r1, [r4, #0x114]
    add r0, r4, #268
    bic r1, r1, #76
    str r1, [r4, #0x114]
    bl     OS_WakeupThread
    ldr r0, [r4, #0x114]
    tst r0, #16
    beq    L_020d56a8
    add r0, r4, #68
    bl     OS_WakeupThreadDirect
L_020d56a8:
    mov r0, r5
    bl     OS_RestoreInterrupts
    cmp r7, #0
    beq    L_020d56c0
    mov r0, r6
    blx r7
L_020d56c0:
    ldr r0, [r4]
    ldr r0, [r0]
    cmp r0, #0
    moveq r0, #1
    movne r0, #0
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
