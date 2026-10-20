#include "m2c.h"

extern M2C_UNK data_0210b320[];
extern M2C_UNK data_0210b460[];
extern M2C_UNK data_0210b380[];

void func_020ae704(void);
s32 WM_GetAllowedChannel(void);
void func_020ad8b4(s32);
void WM_GetDispersionScanPeriod(void);
s32 WM_StartScan(s32, s32);

// clang-format off
asm s32 func_020ae63c(void) {
    stmdb sp!, {r3, lr}
    bl WM_GetAllowedChannel
    cmp r0, #0x8000
    bne L_020ae65c
    mov r0, #0x3
    bl func_020ad8b4
    mov r0, #0x0
    ldmia sp!, {r3, pc}
L_020ae65c:
    cmp r0, #0x0
    bne L_020ae674
    mov r0, #0x16
    bl func_020ad8b4
    mov r0, #0x0
    ldmia sp!, {r3, pc}
L_020ae674:
    ldr r1, =data_0210b320
    ldrh r2, [r1, #0x6]
    cmp r2, #0x0
    bne L_020ae6b8
    mov ip, #0x1
    mov r3, ip
L_020ae68c:
    ldrh r2, [r1, #0x64]
    add r2, r2, #0x1
    strh r2, [r1, #0x64]
    ldrh r2, [r1, #0x64]
    cmp r2, #0x10
    strhih ip, [r1, #0x64]
    ldrh r2, [r1, #0x64]
    sub r2, r2, #0x1
    tst r0, r3, lsl r2
    bne L_020ae6bc
    b L_020ae68c
L_020ae6b8:
    strh r2, [r1, #0x64]
L_020ae6bc:
    bl WM_GetDispersionScanPeriod
    ldr r2, =data_0210b320
    ldr r3, =data_0210b460
    strh r0, [r2, #0x66]
    ldr r0, =func_020ae704
    ldr r1, =data_0210b380
    str r3, [r2, #0x60]
    bl WM_StartScan
    cmp r0, #0x2
    moveq r0, #0x1
    ldmeqia sp!, {r3, pc}
    bl func_020ad8b4
    mov r0, #0x0
    ldmia sp!, {r3, pc}
}
// clang-format on
