#include "m2c.h"

s32 func_02062a7c(s32, s32);

// clang-format off
asm u8 func_0202cc34(s32 arg0, u8 *arg1) {
    stmdb sp!, {r4, lr}
    mov r4, r1
    mov r0, #0x0
    mov r1, #0x63
    bl func_02062a7c
    ldrb r1, [r4, #0x1]
    mov r3, #0x0
    cmp r0, r1
    blo L_0202cc78
L_0202cc58:
    add r2, r4, r3, lsl #0x1
    add r3, r3, #0x1
    add r1, r4, r3, lsl #0x1
    ldrb r2, [r2, #0x1]
    ldrb r1, [r1, #0x1]
    sub r0, r0, r2
    cmp r0, r1
    bhs L_0202cc58
L_0202cc78:
    ldrb r0, [r4, r3, lsl #0x1]
    ldmia sp!, {r4, pc}
}
// clang-format on
