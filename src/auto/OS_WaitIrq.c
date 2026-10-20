#include "m2c.h"

extern u32 SDK_AUTOLOAD_DTCM_START[];
extern u32 OSi_IrqThreadQueue[];

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);
extern void OS_SleepThread(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void OS_WaitIrq(s32 a0, u32 a1) {
    stmfd sp!, {r4, r5, r6, lr}
    mov r5, r0
    mov r4, r1
    bl OS_DisableInterrupts
    cmp r5, #0x0
    beq L_020cc858
    ldr r1, =SDK_AUTOLOAD_DTCM_START
    mvn r2, r4
    add r1, r1, #0x3000
    ldr r3, [r1, #0xff8]
    and r2, r3, r2
    str r2, [r1, #0xff8]
L_020cc858:
    bl OS_RestoreInterrupts
    ldr r1, =SDK_AUTOLOAD_DTCM_START
    add r0, r1, #0x3000
    ldr r0, [r0, #0xff8]
    tst r4, r0
    ldmneia sp!, {r4, r5, r6, pc}
    add r0, r1, #0x3f8
    ldr r5, =OSi_IrqThreadQueue
    add r6, r0, #0x3c00
L_020cc87c:
    mov r0, r5
    bl OS_SleepThread
    ldr r0, [r6, #0x0]
    tst r4, r0
    beq L_020cc87c
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
