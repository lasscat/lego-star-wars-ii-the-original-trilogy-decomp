#include "m2c.h"

extern s32 sUnlockFunc;
extern s32 MBi_ReadyBeaconSendStatus(void);
extern void MBi_InitSendFixedBeacon(void);
extern void MBi_SendFixedBeacon(s32, s32, s32);
extern void MBi_InitSendVolatBeacon(void);
extern void MBi_SendVolatBeacon(s32, s32, s32);

// clang-format off
asm s32 MB_SendGameInfoBeacon(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    ldr r4, =sUnlockFunc
    mov r7, r0
    mov r6, r1
    mov r5, r2
L_020dad3c:
    ldrb r0, [r4, #0x24]
    cmp r0, #0x6
    addls pc, pc, r0, lsl #0x2
    b L_020dad3c
L_020dad4c:
    b L_020dad68
    b L_020dad68
    b L_020dad78
    b L_020dad80
    b L_020dad94
    b L_020dad9c
    b L_020dad3c
L_020dad68:
    bl MBi_ReadyBeaconSendStatus
    cmp r0, #0x0
    bne L_020dad3c
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020dad78:
    bl MBi_InitSendFixedBeacon
    b L_020dad3c
L_020dad80:
    mov r0, r7
    mov r1, r6
    mov r2, r5
    bl MBi_SendFixedBeacon
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_020dad94:
    bl MBi_InitSendVolatBeacon
    b L_020dad3c
L_020dad9c:
    mov r0, r7
    mov r1, r6
    mov r2, r5
    bl MBi_SendVolatBeacon
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
