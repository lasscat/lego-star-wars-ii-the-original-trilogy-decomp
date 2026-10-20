#include "m2c.h"

s32 func_02062a7c(s32, s32);
void func_0209f948(s32, s32);
void func_02010a24(s32, s32);

// clang-format off
asm void func_02010828(s32 *arg0, s32 *arg1, ...) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x8
    movs r5, r1
    mov r6, r0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r4, r5, r6, pc}
    add r0, r6, #0x100
    ldrh r4, [r0, #0x82]
    ldrb ip, [sp, #0x18]
    add r0, r6, #0xd4
    str ip, [sp, #0x0]
    ldr ip, [r0, #0x0]
    ldr ip, [ip, #0x8]
    blx ip
    add r0, r6, #0x100
    ldrh r1, [r0, #0x82]
    cmp r1, #0x0
    cmpne r1, #0x9
    bne L_020108c8
    ldrh r0, [r6, #0xc]
    sub r0, r0, #0x1
    cmp r0, #0x1
    bhi L_020108c8
    cmp r4, r1
    beq L_020108c8
    ldr r0, [r6, #0x148]
    cmp r0, #0x0
    moveq r0, #0x0
    beq L_020108a8
    ldr r0, [r0, #0x8]
    ldrh r0, [r0, #0x4]
    mov r0, r0, lsl #0xc
L_020108a8:
    mov r0, r0, asr #0xc
    sub r1, r0, #0x1
    mov r0, #0x0
    bl func_02062a7c
    mov r1, r0, lsl #0xc
    add r0, r6, #0xd4
    str r1, [sp, #0x4]
    bl func_0209f948
L_020108c8:
    ldrh r0, [r5, #0x0]
    cmp r0, #0x78
    blo L_020108e0
    cmp r0, #0xa0
    addls sp, sp, #0x8
    ldmlsia sp!, {r4, r5, r6, pc}
L_020108e0:
    ldrh r1, [r5, #0x4]
    mov r0, r6
    bl func_02010a24
    add sp, sp, #0x8
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
