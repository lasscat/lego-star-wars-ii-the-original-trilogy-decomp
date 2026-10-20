#include "m2c.h"

void func_020675d8(s32);
void func_0206763c(s32);

// clang-format off
asm void func_0208fa54(s32 *obj) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r5, r0
    ldrb r0, [r5, #0x47c]
    mov r4, #0x0
    cmp r0, #0x0
    ldmlsia sp!, {r4, r5, r6, pc}
    add r6, r5, #0x7c
L_0208fa70:
    add r2, r5, r4, lsl #0x2
    add r0, r2, #0x400
    ldrh r1, [r0, #0x7e]
    cmp r1, #0x0
    bne L_0208fb08
    ldr r0, [r5, #0x38c]
    ldrb r1, [r2, #0x481]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_020675d8
    ldr r1, [r5, #0x38c]
    add r0, r5, r4, lsl #0x2
    ldr r2, [r1, #0x4]
    ldrb r1, [r0, #0x480]
    add r0, r2, #0x28
    bl func_0206763c
    ldrb r1, [r5, #0x47c]
    sub r0, r1, #0x1
    cmp r4, r0
    bhs L_0208faf8
    add r0, r5, r1, lsl #0x2
    add r0, r0, #0x400
    ldrh r2, [r0, #0x7a]
    add r1, r5, r4, lsl #0x2
    add r0, r1, #0x400
    strh r2, [r0, #0x7e]
    ldrb r0, [r5, #0x47c]
    add r0, r5, r0, lsl #0x2
    ldrb r0, [r0, #0x47c]
    strb r0, [r1, #0x480]
    ldrb r0, [r5, #0x47c]
    add r0, r5, r0, lsl #0x2
    ldrb r0, [r0, #0x47d]
    strb r0, [r1, #0x481]
L_0208faf8:
    ldrb r0, [r6, #0x400]
    sub r0, r0, #0x1
    strb r0, [r6, #0x400]
    b L_0208fb10
L_0208fb08:
    sub r1, r1, #0x1
    strh r1, [r0, #0x7e]
L_0208fb10:
    ldrb r0, [r5, #0x47c]
    add r4, r4, #0x1
    cmp r4, r0
    blo L_0208fa70
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
