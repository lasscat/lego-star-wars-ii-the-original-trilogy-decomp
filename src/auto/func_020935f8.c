#include "m2c.h"

extern s32 func_02067b18(s32);
extern s32 func_02067b0c(s32, s32);

// clang-format off
asm s32 func_020935f8(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r0, [r0, #0x68]
    mvn r4, #0x0
    ldr r0, [r0, #0x38c]
    mov r9, r2
    ldr r0, [r0, #0x4]
    mov r5, r4
    ldr r0, [r0, #0x34]
    add r8, r0, r1, lsl #0x3
    mov r0, r8
    bl func_02067b18
    mov r6, r0
    cmp r6, #0x0
    mov r7, #0x0
    ble L_02093688
L_02093634:
    mov r0, r8
    mov r1, r7
    bl func_02067b0c
    ldrsh r2, [r0, #0x2]
    ldr r1, [r9, #0x4]
    ldrsh ip, [r0, #0x0]
    sub r2, r2, r1, asr #0xc
    mul r1, r2, r2
    ldr r3, [r9, #0x0]
    sub r2, ip, r3, asr #0xc
    mla r1, r2, r2, r1
    ldrsh r2, [r0, #0x4]
    ldr r0, [r9, #0x8]
    sub r2, r2, r0, asr #0xc
    mla r0, r2, r2, r1
    cmp r0, r4
    movlo r5, r7
    add r7, r7, #0x1
    movlo r4, r0
    cmp r7, r6
    blt L_02093634
L_02093688:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
