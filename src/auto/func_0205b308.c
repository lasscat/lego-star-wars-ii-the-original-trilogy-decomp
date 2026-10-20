#include "m2c.h"

void func_0205b5d8(s32 *);
void func_0205e5b0(s32, s32);
void func_0205e84c(s32);
void func_0205b3cc(s32, s32 *);

// clang-format off
asm void func_0205b308(s32 *arg0, s32 arg1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0xc
    mov r8, r0
    ldr r5, [r8, #0x8]
    add r6, r8, #0x4
    mov r7, r1
    str r5, [sp, #0x8]
    cmp r5, r6
    addeq sp, sp, #0xc
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, pc}
    add r9, sp, #0x0
    add r4, sp, #0x4
L_0205b338:
    mov r0, r4
    str r5, [sp, #0x4]
    bl func_0205b5d8
    ldr r0, [r5, #0x10]
    ldr r2, [r0, #0x8]
    mov r1, r2, lsl #0x8
    movs r1, r1, lsr #0x1f
    bne L_0205b3b4
    cmp r7, #0x0
    bne L_0205b384
    mov r1, r2, lsl #0x9
    movs r1, r1, lsr #0x19
    beq L_0205b384
    sub r1, r1, #0x1
    bic r2, r2, #0x7f0000
    mov r1, r1, lsl #0x19
    orr r1, r2, r1, lsr #0x9
    str r1, [r0, #0x8]
    b L_0205b3b4
L_0205b384:
    ldr r0, [r0, #0x8]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    strh r0, [sp, #0x0]
    ldr r0, [r5, #0x10]
    ldr r0, [r0, #0x0]
    bl func_0205e5b0
    ldr r0, [r5, #0x10]
    bl func_0205e84c
    mov r0, r8
    mov r1, r9
    bl func_0205b3cc
L_0205b3b4:
    ldr r5, [sp, #0x4]
    cmp r5, r6
    bne L_0205b338
    str r5, [sp, #0x8]
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
