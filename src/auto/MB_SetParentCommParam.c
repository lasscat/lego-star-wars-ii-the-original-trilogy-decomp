#include "m2c.h"

extern u32 WM_DMA_NO[];

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);
extern s32 MBi_IsCommSizeValid(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void MB_SetParentCommParam(s32 a0, s32 a1) {
    stmfd sp!, {r4, r5, r6, lr}
    mov r5, r0
    mov r4, r1
    bl OS_DisableInterrupts
    ldr r1, =WM_DMA_NO
    mov r6, r0
    ldr r1, [r1, #0x8]
    ldrb r1, [r1, #0x50d]
    cmp r1, #0x0
    beq L_020dc6cc
    bl OS_RestoreInterrupts
    mov r0, #0x0
    ldmia sp!, {r4, r5, r6, pc}
L_020dc6cc:
    mov r0, r5
    mov r2, r4
    mov r1, #0x8
    bl MBi_IsCommSizeValid
    cmp r0, #0x0
    bne L_020dc6f4
    mov r0, r6
    bl OS_RestoreInterrupts
    mov r0, #0x0
    ldmia sp!, {r4, r5, r6, pc}
L_020dc6f4:
    ldr r2, =WM_DMA_NO
    mov r0, r6
    ldr r1, [r2, #0x8]
    mov r3, #0x8
    strh r4, [r1, #0x10]
    ldr r1, [r2, #0x8]
    add r1, r1, #0x500
    strh r5, [r1, #0x0]
    ldr r1, [r2, #0x8]
    add r1, r1, #0x500
    strh r3, [r1, #0x2]
    bl OS_RestoreInterrupts
    mov r0, #0x1
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
