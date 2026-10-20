#include "m2c.h"

extern u32 sCommandArray[];
extern u32 data_02116800[];
extern u32 data_021172c8[];
extern u32 sFreeList[];
extern u32 sSharedWork[];
extern u32 SNDi_SharedWork[];

void InitPXI(void);
void SNDi_InitSharedWork(void);
s32 SND_AllocCommand(s32);
void SND_PushCommand(s32);
void SND_FlushCommand(s32);

// clang-format off
asm void SND_CommandInit(void) {
    stmdb sp!, {r4, lr}
    bl InitPXI
    ldr lr, =sCommandArray
    ldr r0, =sFreeList
    mov r4, #0x0
    str lr, [r0, #0x0]
    mov r0, #0x18
    mov r1, r0
    b L_020d08b0
L_020d089c:
    add r3, r4, #0x1
    mul r2, r4, r1
    mla ip, r3, r0, lr
    mov r4, r3
    str ip, [lr, r2]
L_020d08b0:
    cmp r4, #0xff
    blt L_020d089c
    ldr r0, =data_02116800
    mov r3, #0x0
    str r3, [r0, #0xac8]
    ldr r1, =data_021172c8
    ldr r2, =sFreeList
    mov r0, #0x1
    str r1, [r2, #0x10]
    str r3, [r2, #0x8]
    str r3, [r2, #0xc]
    str r3, [r2, #0x1c]
    str r3, [r2, #0x14]
    str r3, [r2, #0x18]
    str r0, [r2, #0x20]
    ldr r0, =sSharedWork
    ldr r1, =SNDi_SharedWork
    str r3, [r2, #0x4]
    str r0, [r1, #0x0]
    bl SNDi_InitSharedWork
    mov r0, #0x1
    bl SND_AllocCommand
    cmp r0, #0x0
    ldmeqia sp!, {r4, pc}
    mov r2, #0x1d
    ldr r1, =SNDi_SharedWork
    str r2, [r0, #0x4]
    ldr r1, [r1, #0x0]
    str r1, [r0, #0x8]
    bl SND_PushCommand
    mov r0, #0x1
    bl SND_FlushCommand
    ldmia sp!, {r4, pc}
}
// clang-format on
