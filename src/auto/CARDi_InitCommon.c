#include "m2c.h"

extern u32 cardi_common[];
extern u32 cardi_arg[];
extern void MIi_CpuClearFast();
extern void DC_FlushRange();
extern void MI_CpuCopy8();
extern void CARDi_TaskThread();
extern u32 cardi_rom_base[];
extern void OS_CreateThread();
extern void OS_WakeupThreadDirect();
extern void CARDi_OnFifoRecv();
extern void PXI_SetFifoRecvCallback();
extern void CARD_Enable();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARDi_InitCommon(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #8
    ldr     r4, =cardi_common
    ldr     r1, =cardi_arg
    mvn r2, #2
    mov r0, #0
    str r2, [r4, #8]
    mov r2, #96
    str r0, [r4, #0xc]
    str r0, [r4, #0x18]
    str r1, [r4]
    bl     MIi_CpuClearFast
    ldr     r0, =cardi_arg
    mov r1, #96
    bl     DC_FlushRange
    ldr     r0, =0x27ffc40
    ldrh r0, [r0]
    cmp r0, #2
    moveq r0, #1
    movne r0, #0
    cmp r0, #0
    bne    L_020d4edc
    ldr     r0, =0x27ffe00
    mov r2, #352
    sub r1, r0, #896
    bl     MI_CpuCopy8
L_020d4edc:
    mov r2, #0
    mov r0, #4
    str r0, [r4, #0x108]
    str r2, [r4, #0x14]
    str r2, [r4, #0x10]
    str r2, [r4, #0x110]
    str r2, [r4, #0x10c]
    mov r0, #1024
    str r0, [sp]
    ldr ip, [r4, #0x108]
    ldr     r1, =CARDi_TaskThread
    ldr     r3, =cardi_rom_base
    add r0, r4, #68
    str ip, [sp, #4]
    bl     OS_CreateThread
    add r0, r4, #68
    bl     OS_WakeupThreadDirect
    ldr     r1, =CARDi_OnFifoRecv
    mov r0, #11
    bl     PXI_SetFifoRecvCallback
    ldr     r0, =0x27ffc40
    ldrh r0, [r0]
    cmp r0, #2
    moveq r0, #1
    movne r0, #0
    cmp r0, #0
    addne sp, sp, #8
    ldmneia sp!, {r4, pc}
    mov r0, #1
    bl     CARD_Enable
    add sp, sp, #8
    ldmia sp!, {r4, pc}
}
// clang-format on
