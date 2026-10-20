#include "m2c.h"

void func_0206763c(s32);
void func_020675d8(s32);

// clang-format off
asm void func_0209075c(s32 *obj, s32 idx) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    add r2, r5, #0x3e8
    ldr r0, [r2, r1, lsl #0x3]
    add r4, r2, r1, lsl #0x3
    subs r0, r0, #0x1
    str r0, [r2, r1, lsl #0x3]
    bne L_020907b4
    ldrb r1, [r4, #0x6]
    cmp r1, #0x0
    beq L_02090798
    ldr r0, [r5, #0x38c]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_0206763c
L_02090798:
    ldrb r1, [r4, #0x7]
    cmp r1, #0x0
    beq L_020907b4
    ldr r0, [r5, #0x38c]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_020675d8
L_020907b4:
    ldrb r1, [r4, #0x5]
    cmp r1, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r0, [r5, #0x38c]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_020675d8
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
