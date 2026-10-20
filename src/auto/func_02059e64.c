#include "m2c.h"

void func_02059e4c(s32);

// clang-format off
asm void func_02059e64(s32 *obj, s32 val) {
    stmdb sp!, {r3, lr}
    ldrb r2, [r0, #0x8]
    cmp r2, #0x0
    beq L_02059e7c
    bl func_02059e4c
    ldmia sp!, {r3, pc}
L_02059e7c:
    ldrh r3, [r0, #0x0]
    mov r2, #0x0
    mov r1, r1, lsl #0x10
    strh r3, [r0, #0x2]
    orr r1, r2, r1, lsr #0x10
    strh r1, [r0, #0x0]
    ldrh r2, [r0, #0x0]
    ldrh r1, [r0, #0x2]
    eor r1, r2, r1
    and r1, r2, r1
    strh r1, [r0, #0x4]
    ldrh r2, [r0, #0x2]
    ldrh r1, [r0, #0x0]
    eor r1, r1, r2
    and r1, r2, r1
    strh r1, [r0, #0x6]
    ldmia sp!, {r3, pc}
}
// clang-format on
