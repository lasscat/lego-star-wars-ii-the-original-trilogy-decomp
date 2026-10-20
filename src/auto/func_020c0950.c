#include "m2c.h"

// clang-format off
asm void func_020c0950(s32 *obj) {
    stmdb sp!, {r4, lr}
    ldr r2, [r0, #0x0]
    mov r4, r0
    ldr r2, [r2, #0x0]
    blx r2
    ldrb r0, [r4, #0x14]
    cmp r0, #0x0
    moveq r0, #0x0
    beq L_020c0988
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
    mov r0, #0x1
L_020c0988:
    strb r0, [r4, #0x15]
    mov r0, #0x0
    str r0, [r4, #0xc]
    str r0, [r4, #0x10]
    ldmia sp!, {r4, pc}
}
// clang-format on
