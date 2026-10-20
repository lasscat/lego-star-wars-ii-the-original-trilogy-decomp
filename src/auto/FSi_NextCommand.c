#include "m2c.h"

extern void OS_DisableInterrupts();
extern void FSi_ReleaseCommand();
extern void OS_RestoreInterrupts();
extern void OS_WakeupThread();
extern void func_020d2898();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_NextCommand(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #72
    mov r6, r0
    bl     OS_DisableInterrupts
    ldr r1, [r6, #0x1c]
    mov r4, r0
    tst r1, #32
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d211c
    ldr r0, [r6, #0x1c]
    bic r0, r0, #32
    str r0, [r6, #0x1c]
    ldr r0, [r6, #0x24]
    cmp r0, #0
    beq    L_020d211c
    mov r8, #0
    mov r9, #1
    mov r7, #3
L_020d20d8:
    ldr r1, [r0, #0xc]
    ldr r5, [r0, #4]
    tst r1, #2
    movne r1, r9
    moveq r1, r8
    cmp r1, #0
    beq    L_020d2110
    ldr r1, [r6, #0x24]
    cmp r1, r0
    mov r1, r7
    streq r5, [r6, #0x24]
    bl     FSi_ReleaseCommand
    cmp r5, #0
    ldreq r5, [r6, #0x24]
L_020d2110:
    mov r0, r5
    cmp r5, #0
    bne    L_020d20d8
L_020d211c:
    ldr r0, [r6, #0x1c]
    tst r0, #64
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    bne    L_020d220c
    ldr r0, [r6, #0x1c]
    tst r0, #8
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    bne    L_020d220c
    ldr r5, [r6, #0x24]
    cmp r5, #0
    beq    L_020d220c
    ldr r0, [r6, #0x1c]
    tst r0, #16
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    moveq r7, #1
    movne r7, #0
    cmp r7, #0
    ldrne r0, [r6, #0x1c]
    orrne r0, r0, #16
    strne r0, [r6, #0x1c]
    mov r0, r4
    bl     OS_RestoreInterrupts
    cmp r7, #0
    beq    L_020d21b0
    ldr r0, [r6, #0x58]
    tst r0, #512
    beq    L_020d21b0
    ldr r2, [r6, #0x54]
    mov r0, r5
    mov r1, #9
    blx r2
L_020d21b0:
    bl     OS_DisableInterrupts
    ldr r1, [r5, #0xc]
    mov r4, r0
    orr r0, r1, #64
    str r0, [r5, #0xc]
    ldr r0, [r5, #0xc]
    tst r0, #4
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d21f8
    add r0, r5, #24
    bl     OS_WakeupThread
    mov r0, r4
    bl     OS_RestoreInterrupts
    add sp, sp, #72
    mov r0, #0
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
L_020d21f8:
    mov r0, r4
    bl     OS_RestoreInterrupts
    add sp, sp, #72
    mov r0, r5
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
L_020d220c:
    ldr r0, [r6, #0x1c]
    tst r0, #16
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d2258
    ldr r0, [r6, #0x1c]
    bic r0, r0, #16
    str r0, [r6, #0x1c]
    ldr r0, [r6, #0x58]
    tst r0, #1024
    beq    L_020d2258
    add r0, sp, #0
    bl     func_020d2898
    str r6, [sp, #8]
    ldr r2, [r6, #0x54]
    add r0, sp, #0
    mov r1, #10
    blx r2
L_020d2258:
    ldr r0, [r6, #0x1c]
    tst r0, #64
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d2288
    ldr r1, [r6, #0x1c]
    add r0, r6, #20
    bic r1, r1, #64
    orr r1, r1, #8
    str r1, [r6, #0x1c]
    bl     OS_WakeupThread
L_020d2288:
    mov r0, r4
    bl     OS_RestoreInterrupts
    mov r0, #0
    add sp, sp, #72
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
