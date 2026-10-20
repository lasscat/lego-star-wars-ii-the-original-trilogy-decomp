#include "m2c.h"

extern s32 cardi_common;

extern s32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(s32);
extern void OS_SleepThread(s32);
extern s32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(void);
extern void OS_WakeupThread(s32);
extern void OS_WakeupThreadDirect(s32);

// clang-format off
asm s32 CARDi_ReadRomID(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    ldr r4, =cardi_common
    bl OS_DisableInterrupts
    mov r5, r0
    b L_020d5bb0
L_020d5ba8:
    add r0, r4, #0x10c
    bl OS_SleepThread
L_020d5bb0:
    ldr r0, [r4, #0x114]
    tst r0, #0x4
    bne L_020d5ba8
    ldr r0, [r4, #0x114]
    mov r1, #0x0
    orr r2, r0, #0x4
    mov r0, r5
    str r2, [r4, #0x114]
    str r1, [r4, #0x38]
    str r1, [r4, #0x3c]
    bl OS_RestoreInterrupts
    bl CARDi_ReadRomIDCore
    ldr r8, =cardi_common
    mov r4, r0
    bl CARDi_ReadRomIDCore
    bl CARDi_CheckPulledOutCore
    ldr r0, [r8, #0x0]
    mov r1, #0x0
    str r1, [r0, #0x0]
    ldr r5, [r8, #0x38]
    ldr r6, [r8, #0x3c]
    bl OS_DisableInterrupts
    ldr r1, [r8, #0x114]
    mov r7, r0
    bic r0, r1, #0x4c
    str r0, [r8, #0x114]
    add r0, r8, #0x10c
    bl OS_WakeupThread
    ldr r0, [r8, #0x114]
    tst r0, #0x10
    beq L_020d5c34
    add r0, r8, #0x44
    bl OS_WakeupThreadDirect
L_020d5c34:
    mov r0, r7
    bl OS_RestoreInterrupts
    cmp r5, #0x0
    beq L_020d5c4c
    mov r0, r6
    blx r5
L_020d5c4c:
    mov r0, r4
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
