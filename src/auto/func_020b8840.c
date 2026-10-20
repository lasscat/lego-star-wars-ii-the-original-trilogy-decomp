#include "m2c.h"

extern u32 data_0210daf0[];

s32 func_020b8b1c(s32);

// clang-format off
asm void func_020b8840(s32 arg0) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r2, =data_0210daf0
    mov r1, #0x24
    ldr r5, [r2, #0x0]
    add r2, r5, #0x3c
    mla r4, r0, r1, r2
    ldrb r3, [r4, #0x8]
    cmp r3, #0xff
    ldrneb r0, [r4, #0x1]
    cmpne r0, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    add r0, r5, #0xbc
    add r2, r0, #0x400
    ldr r1, [r4, #0xc]
    ldr r0, [r2, r3, lsl #0x5]
    add r5, r2, r3, lsl #0x5
    cmp r0, r1
    bls L_020b88d0
    ldrb r1, [r4, #0x11]
    mov r1, r1, lsl #0x2
    rsb r1, r1, #0x0
    bl func_020b8b1c
    str r0, [r5, #0x0]
    ldr r1, [r4, #0xc]
    cmp r0, r1
    strlo r1, [r5, #0x0]
    ldrb r1, [r5, #0x11]
    mov r0, r1, lsl #0x1e
    mov r0, r0, lsr #0x1e
    orr r0, r0, #0x1
    and r0, r0, #0xff
    bic r1, r1, #0x3
    and r0, r0, #0x3
    orr r0, r1, r0
    strb r0, [r5, #0x11]
    ldmia sp!, {r3, r4, r5, pc}
L_020b88d0:
    ldmhsia sp!, {r3, r4, r5, pc}
    ldrb r1, [r4, #0x11]
    mov r1, r1, lsl #0x2
    bl func_020b8b1c
    str r0, [r5, #0x0]
    ldr r1, [r4, #0xc]
    cmp r0, r1
    strhi r1, [r5, #0x0]
    ldrb r1, [r5, #0x11]
    mov r0, r1, lsl #0x1e
    mov r0, r0, lsr #0x1e
    orr r0, r0, #0x1
    and r0, r0, #0xff
    bic r1, r1, #0x3
    and r0, r0, #0x3
    orr r0, r1, r0
    strb r0, [r5, #0x11]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
