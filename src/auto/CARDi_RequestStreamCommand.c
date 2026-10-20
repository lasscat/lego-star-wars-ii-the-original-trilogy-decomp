#include "m2c.h"

extern u32 cardi_common[];
extern void OSi_ReferSymbol();
extern void OS_DisableInterrupts();
extern void OS_SleepThread();
extern void OS_RestoreInterrupts();
extern void CARDi_RequestStreamCommandCore();
extern void CARDi_SetTask();
extern u32 OSi_ThreadInfo[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARDi_RequestStreamCommand(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    ldr     r4, =cardi_common
    ldr     r0, =0x2000ba8
    mov r8, r1
    mov r7, r2
    mov r6, r3
    bl     OSi_ReferSymbol
    bl     OS_DisableInterrupts
    ldr r1, [r4, #0x114]
    mov r5, r0
    tst r1, #4
    beq    L_020d54f8
L_020d54e4:
    add r0, r4, #268
    bl     OS_SleepThread
    ldr r0, [r4, #0x114]
    tst r0, #4
    bne    L_020d54e4
L_020d54f8:
    ldr r0, [r4, #0x114]
    ldr r1, [sp, #0x20]
    orr r2, r0, #4
    mov r0, r5
    str r2, [r4, #0x114]
    str r6, [r4, #0x38]
    str r1, [r4, #0x3c]
    bl     OS_RestoreInterrupts
    ldr r3, [sp, #0x28]
    ldr r2, [sp, #0x2c]
    ldr r1, [sp, #0x30]
    ldr r0, [sp, #0x24]
    str sb, [r4, #0x1c]
    str r8, [r4, #0x20]
    str r7, [r4, #0x24]
    str r3, [r4, #0x2c]
    str r2, [r4, #0x30]
    str r1, [r4, #0x34]
    cmp r0, #0
    beq    L_020d5558
    ldr     r0, =CARDi_RequestStreamCommandCore
    bl     CARDi_SetTask
    mov r0, #1
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
L_020d5558:
    ldr     r0, =OSi_ThreadInfo
    ldr     r1, =cardi_common
    ldr r2, [r0, #4]
    mov r0, r4
    str r2, [r1, #0x104]
    bl     CARDi_RequestStreamCommandCore
    ldr r0, [r4]
    ldr r0, [r0]
    cmp r0, #0
    moveq r0, #1
    movne r0, #0
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
