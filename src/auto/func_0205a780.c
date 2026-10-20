#include "m2c.h"

// clang-format off
asm s32 func_0205a780(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r0, [r5, #0x28]
    mov r4, r1
    tst r0, #0x1
    add r0, r5, r0, asr #0x1
    ldreq r3, [r5, #0x24]
    beq L_0205a7ac
    ldr r3, [r0, #0x0]
    ldr r1, [r5, #0x24]
    ldr r3, [r3, r1]
L_0205a7ac:
    mov r1, r4
    blx r3
    ldr r2, [r5, #0x0]
    mov r1, r4, lsl #0x1e
    ldrb r2, [r2, r0]
    mov r0, r1, lsr #0x1d
    mov r0, r2, asr r0
    and r0, r0, #0xff
    and r0, r0, #0x3
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
