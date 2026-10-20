#include "m2c.h"

extern u32 data_0211748c[];

extern void PMi_SetLED(s32);
extern void PMi_SetLEDAsync(s32, s32);

// clang-format off
asm void PMi_SetLCDPower(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, lr}
    cmp r0, #0x0
    beq L_020d42e4
    cmp r0, #0x1
    bne L_020d432c
    cmp r2, #0x0
    bne L_020d42a8
    ldr r2, =0x27ffc3c
    ldr r0, =data_0211748c
    ldr r2, [r2, #0x0]
    ldr r0, [r0, #0x10]
    sub r0, r2, r0
    cmp r0, #0x7
    movls r0, #0x0
    ldmlsia sp!, {r3, pc}
L_020d42a8:
    cmp r1, #0x0
    beq L_020d42d0
    cmp r3, #0x0
    mov r0, r1
    beq L_020d42c4
    bl PMi_SetLED
    b L_020d42d0
L_020d42c4:
    mov r1, #0x0
    mov r2, r1
    bl PMi_SetLEDAsync
L_020d42d0:
    ldr r1, =0x4000304
    ldrh r0, [r1, #0x0]
    orr r0, r0, #0x1
    strh r0, [r1, #0x0]
    b L_020d432c
L_020d42e4:
    ldr lr, =0x4000304
    ldr r2, =0x27ffc3c
    ldrh ip, [lr, #0x0]
    ldr r0, =data_0211748c
    cmp r1, #0x0
    bic ip, ip, #0x1
    strh ip, [lr, #0x0]
    ldr r2, [r2, #0x0]
    str r2, [r0, #0x10]
    beq L_020d432c
    cmp r3, #0x0
    mov r0, r1
    beq L_020d4320
    bl PMi_SetLED
    b L_020d432c
L_020d4320:
    mov r1, #0x0
    mov r2, r1
    bl PMi_SetLEDAsync
L_020d432c:
    mov r0, #0x1
    ldmia sp!, {r3, pc}
}
// clang-format on
