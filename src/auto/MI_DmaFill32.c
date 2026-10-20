#include "m2c.h"

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);
extern void MIi_DmaSetParams_wait_noInt(s32 a0, s32 a1, s32 a2, s32 a3);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void MI_DmaFill32(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmfd sp!, {r4, r5, r6, r7, r8, lr}
    movs r4, r3
    mov r8, r0
    mov r7, r1
    mov r6, r2
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    add r0, r8, r8, lsl #0x1
    add r0, r0, #0x2
    mov r0, r0, lsl #0x2
    add r0, r0, #0xb0
    add r5, r0, #0x4000000
L_020ceacc:
    ldr r0, [r5, #0x0]
    tst r0, #0x80000000
    bne L_020ceacc
    bl OS_DisableInterrupts
    mov r2, r8, lsl #0x2
    add r1, r2, #0xe0
    mov r3, r4, lsr #0x2
    mov r4, r0
    add ip, r2, #0x4000000
    mov r0, r8
    mov r2, r7
    add r1, r1, #0x4000000
    orr r3, r3, #0x85000000
    str r6, [ip, #0xe0]
    bl MIi_DmaSetParams_wait_noInt
    mov r0, r4
    bl OS_RestoreInterrupts
L_020ceb10:
    ldr r0, [r5, #0x0]
    tst r0, #0x80000000
    bne L_020ceb10
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
