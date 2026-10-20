#include "m2c.h"

extern s32 data_0210930c;
extern void func_0205e860(s32);

// clang-format off
asm void func_02083a5c(s32 a0) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r5, r0
    ldrb r0, [r5, #0x50]
    mov r6, #0x0
    cmp r0, #0x0
    ble L_02083aa4
    mov r4, r6
L_02083a78:
    ldr r0, [r5, r6, lsl #0x2]
    cmp r0, #0x0
    beq L_02083a90
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_02083a90:
    str r4, [r5, r6, lsl #0x2]
    ldrb r0, [r5, #0x50]
    add r6, r6, #0x1
    cmp r6, r0
    blt L_02083a78
L_02083aa4:
    mov r4, #0x0
    ldr r0, =data_0210930c
    strb r4, [r5, #0x50]
    ldr r0, [r0, #0x68]
    ldr r0, [r0, #0x38c]
    ldr r0, [r0, #0x4]
    ldrh r7, [r0, #0x40]
    cmp r7, #0x0
    ble L_02083af4
    mov r6, r4
L_02083acc:
    ldr r0, [r5, #0x54]
    ldr r0, [r0, r4, lsl #0x2]
    cmp r0, #0x0
    beq L_02083ae0
    bl func_0205e860
L_02083ae0:
    ldr r0, [r5, #0x54]
    str r6, [r0, r4, lsl #0x2]
    add r4, r4, #0x1
    cmp r4, r7
    blt L_02083acc
L_02083af4:
    ldr r0, [r5, #0x54]
    cmp r0, #0x0
    beq L_02083b04
    bl func_0205e860
L_02083b04:
    mov r0, #0x0
    str r0, [r5, #0x54]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
