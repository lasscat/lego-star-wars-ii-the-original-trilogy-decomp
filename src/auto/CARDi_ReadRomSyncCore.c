#include "m2c.h"

extern M2C_UNK rom_stat[];
extern M2C_UNK cardi_common[];

void CARDi_ReadFromCache(s32);
void CARDi_ReadRomIDCore(s32);
void CARDi_CheckPulledOutCore(s32);
s32 OS_DisableInterrupts(void);
void OS_WakeupThread(s32);
void OS_WakeupThreadDirect(s32);
void OS_RestoreInterrupts(s32);

// clang-format off
asm void CARDi_ReadRomSyncCore(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    ldr r4, =rom_stat
    mov r0, r4
    bl CARDi_ReadFromCache
    cmp r0, #0x0
    beq L_020d5c7c
    ldr r1, [r4, #0x0]
    mov r0, r4
    blx r1
L_020d5c7c:
    ldr r4, =cardi_common
    bl CARDi_ReadRomIDCore
    bl CARDi_CheckPulledOutCore
    ldr r0, [r4, #0x0]
    mov r1, #0x0
    str r1, [r0, #0x0]
    ldr r5, [r4, #0x38]
    ldr r6, [r4, #0x3c]
    bl OS_DisableInterrupts
    ldr r1, [r4, #0x114]
    mov r7, r0
    bic r0, r1, #0x4c
    str r0, [r4, #0x114]
    add r0, r4, #0x10c
    bl OS_WakeupThread
    ldr r0, [r4, #0x114]
    tst r0, #0x10
    beq L_020d5ccc
    add r0, r4, #0x44
    bl OS_WakeupThreadDirect
L_020d5ccc:
    mov r0, r7
    bl OS_RestoreInterrupts
    cmp r5, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r6
    blx r5
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
