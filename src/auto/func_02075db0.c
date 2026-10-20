#include "m2c.h"

extern M2C_UNK data_020fed00[];

// clang-format off
asm s32 func_02075db0(s32 *obj) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r1, =data_020fed00
    mov r6, r0
    mov r5, #0x0
    str r1, [r6, #0x0]
    mov r4, r5
L_02075dc8:
    add r0, r6, r5, lsl #0x2
    ldr r0, [r0, #0xc]
    cmp r0, #0x0
    beq L_02075de4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_02075de4:
    add r0, r6, r5, lsl #0x2
    add r5, r5, #0x1
    str r4, [r0, #0xc]
    cmp r5, #0x4
    blt L_02075dc8
    mov r0, r6
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
