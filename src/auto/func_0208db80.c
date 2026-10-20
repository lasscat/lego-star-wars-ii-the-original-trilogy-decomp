#include "m2c.h"

s32 func_02062b3c(s32);
s32 func_02062a7c(s32, s32);
s32 func_0208dad8(s32);

// clang-format off
asm s32 func_0208db80(s32 arg0) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    cmp r0, #0x4
    addls pc, pc, r0, lsl #0x2
    b L_0208dbf4
L_0208db90:
    b L_0208dba4
    b L_0208dbb0
    b L_0208dbbc
    b L_0208dbc8
    b L_0208dbd4
L_0208dba4:
    mov r5, #0x0
    mov r4, #0x2c
    b L_0208dbfc
L_0208dbb0:
    mov r5, #0x2d
    mov r4, #0x6a
    b L_0208dbfc
L_0208dbbc:
    mov r5, #0x6b
    mov r4, #0xb0
    b L_0208dbfc
L_0208dbc8:
    mov r5, #0xb1
    mov r4, #0xe7
    b L_0208dbfc
L_0208dbd4:
    mov r0, #0x3c
    mov r5, #0xe8
    mov r4, #0xf9
    bl func_02062b3c
    cmp r0, #0x0
    beq L_0208dbfc
    mov r0, #0xfa
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_0208dbf4:
    mov r0, #0x0
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_0208dbfc:
    mov r7, #0x0
L_0208dc00:
    mov r0, r5
    mov r1, r4
    bl func_02062a7c
    mov r0, r0, lsl #0x10
    mov r6, r0, lsr #0x10
    mov r0, r6
    bl func_0208dad8
    ldrb r0, [r0, #0x18]
    cmp r0, #0x0
    bne L_0208dc40
    add r0, r7, #0x1
    mov r0, r0, lsl #0x10
    mov r7, r0, lsr #0x10
    cmp r7, #0x5
    bls L_0208dc00
    mov r6, r5
L_0208dc40:
    mov r0, r6
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
