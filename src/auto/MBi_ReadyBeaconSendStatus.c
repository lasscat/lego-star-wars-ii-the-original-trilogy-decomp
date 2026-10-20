#include "m2c.h"

extern u32 sUnlockFunc[];
extern u32 bsendBuff[];

extern s32 MBi_GetGgid(void);
extern s32 MBi_GetTgid(void);
extern void WM_SetGameInfo(s32 a0, s32 a1, s32 a2, s32 a3);
extern void MBi_ClearSendStatus(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void MBi_ReadyBeaconSendStatus(s32 a0) {
    stmfd sp!, {r4, lr}
    sub sp, sp, #0x8
    ldr r0, =sUnlockFunc
    ldr r1, [r0, #0x18]
    cmp r1, #0x0
    bne L_020dae04
    bl MBi_GetGgid
    mov r4, r0
    bl MBi_GetTgid
    str r0, [sp, #0x0]
    mov ip, #0x8
    ldr r1, =bsendBuff
    mov r3, r4
    mov r0, #0x0
    mov r2, #0x70
    str ip, [sp, #0x4]
    bl WM_SetGameInfo
    add sp, sp, #0x8
    mov r0, #0x0
    ldmia sp!, {r4, pc}
L_020dae04:
    ldr r0, [r0, #0x1c]
    cmp r0, #0x0
    ldrne r1, [r0, #0x4bc]
    cmpne r1, #0x0
    ldreq r0, =sUnlockFunc
    ldreq r1, [r0, #0x18]
    ldr r0, =sUnlockFunc
    str r1, [r0, #0x1c]
    bl MBi_ClearSendStatus
    ldr r1, =sUnlockFunc
    mov r2, #0x2
    ldr r3, [r1, #0x1c]
    mov r0, #0x1
    ldrb r3, [r3, #0x4b4]
    strb r3, [r1, #0x26]
    strb r2, [r1, #0x24]
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
}
// clang-format on
