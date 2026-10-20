#include "m2c.h"

extern u32 data_0210da80[];
extern u32 data_0210da88[];

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);
extern void MI_CpuCopy8(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020b01e0(s32 a0) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x10
    mov r4, r0
    bl OS_DisableInterrupts
    ldr r1, =data_0210da80
    mov r2, #0x1
    mov r2, r2, lsl r4
    ldrh r1, [r1, #0xa]
    mov r4, r2, lsl #0x10
    mov r5, r0
    tst r1, r4, lsr #0x10
    bne L_020b0220
    bl OS_RestoreInterrupts
    add sp, sp, #0x10
    mov r0, #0x0
    ldmia sp!, {r3, r4, r5, pc}
L_020b0220:
    ldr r0, =data_0210da88
    add r1, sp, #0x0
    mov r2, #0xe
    bl MI_CpuCopy8
    mov r0, r5
    bl OS_RestoreInterrupts
    ldrh r0, [sp, #0x4]
    tst r0, r4, lsr #0x10
    addne sp, sp, #0x10
    movne r0, #0x2
    ldmneia sp!, {r3, r4, r5, pc}
    ldrh r0, [sp, #0x6]
    tst r0, r4, lsr #0x10
    addne sp, sp, #0x10
    movne r0, #0x3
    ldmneia sp!, {r3, r4, r5, pc}
    ldrh r0, [sp, #0x8]
    tst r0, r4, lsr #0x10
    addne sp, sp, #0x10
    movne r0, #0x4
    ldmneia sp!, {r3, r4, r5, pc}
    ldrh r0, [sp, #0xa]
    tst r0, r4, lsr #0x10
    addne sp, sp, #0x10
    movne r0, #0x5
    ldmneia sp!, {r3, r4, r5, pc}
    ldrh r0, [sp, #0xc]
    tst r0, r4, lsr #0x10
    movne r0, #0x6
    moveq r0, #0x1
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
