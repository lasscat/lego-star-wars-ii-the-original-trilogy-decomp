#include "m2c.h"

extern void func_0205e80c();
extern void func_0201abbc();
extern void func_02060cd0();
extern void clearDataAndInstructionCache();
extern void func_0201b318();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205e984(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    mov r5, r1
    mov r4, r2
    mov r0, #0x80
    mov r1, #0x0
    mov r2, #0x4
    mov r7, r3
    bl      func_0205e80c
    cmp r0, #0x0
    beq      L_0205e9b8
    mov r1, r7
    bl      func_0201abbc
    L_0205e9b8:
    ldr r1, [r6, #0x0]
    str r0, [r1, r4, lsl #0x2]
    ldr r0, [r6, #0x0]
    ldrb r1, [r5, #0xb]
    ldr r0, [r0, r4, lsl #0x2]
    ldr r2, [r0, #0x8]
    tst r2, #0x80000000
    movne r2, #0x0
    moveq r2, #0x1
    bl      func_02060cd0
    ldr r0, [r6, #0x0]
    mov r1, r5
    ldr r0, [r0, r4, lsl #0x2]
    bl      clearDataAndInstructionCache
    ldr r0, [r6, #0x0]
    ldrb r1, [r5, #0xa]
    ldr r0, [r0, r4, lsl #0x2]
    bl      func_0201b318
    ldrsh r1, [r5, #0x6]
    ldr r0, [r6, #0x0]
    ldr r0, [r0, r4, lsl #0x2]
    mov r1, r1, lsl #0xc
    str r1, [r0, #0x4c]
    ldrsh r1, [r5, #0x8]
    ldr r0, [r6, #0x0]
    ldr r0, [r0, r4, lsl #0x2]
    mov r1, r1, lsl #0xc
    str r1, [r0, #0x50]
    ldrh r0, [r6, #0x6]
    add r0, r0, #0x1
    strh r0, [r6, #0x6]
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
