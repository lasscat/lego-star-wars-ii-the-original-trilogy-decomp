#include "m2c.h"

extern void OS_DisableInterrupts();
extern void FSi_ReleaseCommand();
extern void OS_RestoreInterrupts();
extern void FSi_ExecuteAsyncCommand();
extern void OS_SleepThread();
extern void FSi_ExecuteSyncCommand();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_SendCommand(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    ldr r4, [r6, #8]
    mov r2, #1
    str r1, [r6, #0x10]
    mov r0, #2
    str r0, [r6, #0x14]
    ldr r0, [r6, #0xc]
    mov r7, r2, lsl r1
    orr r0, r0, #1
    str r0, [r6, #0xc]
    bl     OS_DisableInterrupts
    ldr r1, [r4, #0x1c]
    mov r5, r0
    tst r1, #128
    beq    L_020d23d0
    mov r0, r6
    mov r1, #3
    bl     FSi_ReleaseCommand
    mov r0, r5
    bl     OS_RestoreInterrupts
    mov r0, #0
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020d23d0:
    tst r7, #508
    ldrne r0, [r6, #0xc]
    orrne r0, r0, #4
    strne r0, [r6, #0xc]
    ldr r1, [r6]
    ldr r2, [r6, #4]
    cmp r1, #0
    strne r2, [r1, #4]
    cmp r2, #0
    add r0, r4, #32
    strne r1, [r2]
    ldr r1, [r0, #4]
    cmp r1, #0
    beq    L_020d2418
L_020d2408:
    mov r0, r1
    ldr r1, [r1, #4]
    cmp r1, #0
    bne    L_020d2408
L_020d2418:
    str r6, [r0, #4]
    str r0, [r6]
    mov r1, #0
    str r1, [r6, #4]
    ldr r0, [r4, #0x1c]
    tst r0, #8
    movne r1, #1
    cmp r1, #0
    bne    L_020d24c8
    ldr r0, [r4, #0x1c]
    tst r0, #16
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    bne    L_020d24c8
    ldr r1, [r4, #0x1c]
    mov r0, r5
    orr r1, r1, #16
    str r1, [r4, #0x1c]
    bl     OS_RestoreInterrupts
    ldr r0, [r4, #0x58]
    tst r0, #512
    beq    L_020d2484
    ldr r2, [r4, #0x54]
    mov r0, r6
    mov r1, #9
    blx r2
L_020d2484:
    bl     OS_DisableInterrupts
    ldr r1, [r6, #0xc]
    orr r1, r1, #64
    str r1, [r6, #0xc]
    ldr r1, [r6, #0xc]
    tst r1, #4
    movne r1, #1
    moveq r1, #0
    cmp r1, #0
    bne    L_020d24c0
    bl     OS_RestoreInterrupts
    mov r0, r6
    bl     FSi_ExecuteAsyncCommand
    mov r0, #1
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020d24c0:
    bl     OS_RestoreInterrupts
    b      L_020d250c
L_020d24c8:
    ldr r0, [r6, #0xc]
    tst r0, #4
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    bne    L_020d24f0
    mov r0, r5
    bl     OS_RestoreInterrupts
    mov r0, #1
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020d24f0:
    add r0, r6, #24
    bl     OS_SleepThread
    ldr r0, [r6, #0xc]
    tst r0, #64
    beq    L_020d24f0
    mov r0, r5
    bl     OS_RestoreInterrupts
L_020d250c:
    mov r0, r6
    bl     FSi_ExecuteSyncCommand
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
