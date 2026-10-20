#include "m2c.h"

// clang-format off
asm void func_0205a6d0(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    ldr r0, [r6, #0x28]
    mov r5, r1
    tst r0, #0x1
    mov r4, r3
    add r0, r6, r0, asr #0x1
    ldreq r3, [r6, #0x24]
    beq L_0205a700
    ldr r3, [r0, #0x0]
    ldr r1, [r6, #0x24]
    ldr r3, [r3, r1]
L_0205a700:
    mov r1, r5
    blx r3
    ldr r3, [r6, #0x0]
    mov r1, r5, lsl #0x1e
    mov r5, r1, lsr #0x1d
    mov r1, #0x3
    ldrb r2, [r3, r0]
    mvn r1, r1, lsl r5
    and r1, r2, r1
    strb r1, [r3, r0]
    ldr r3, [r6, #0x0]
    and r1, r4, #0x3
    ldrb r2, [r3, r0]
    orr r1, r2, r1, lsl r5
    strb r1, [r3, r0]
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
