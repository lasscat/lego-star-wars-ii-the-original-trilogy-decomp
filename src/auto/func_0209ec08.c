#include "m2c.h"

extern u32 data_021027f8[];
extern u32 data_02109358[];
extern u32 data_020f7806[];

void clearDataAndInstructionCache(s32, s32, s32);
void func_0201a934(s32, s32, s32, s32);

// clang-format off
asm void func_0209ec08(s32 *arg0) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0xc
    ldr r1, =data_021027f8
    ldr r2, =data_02109358
    ldrb r1, [r1, #0x2a]
    mov r4, r0
    ldr r6, [r2, r1, lsl #0x2]
    ldrb r1, [r6, #0x6bb]
    cmp r1, #0x54
    blo L_0209ec60
    cmp r1, #0x63
    bhi L_0209ec60
    ldrb r0, [r4, #0x32]
    sub r5, r1, #0x54
    cmp r0, r5
    beq L_0209ec60
    ldr r1, =data_020f7806
    mov r0, #0x6
    mla r1, r5, r0, r1
    ldr r0, [r4, #0x14]
    bl clearDataAndInstructionCache
    strb r5, [r4, #0x32]
L_0209ec60:
    ldrh r0, [r6, #0xca]
    mov r1, #0x1000
    mov ip, #0x8000
    rsb r0, r0, #0x0
    mov r0, r0, lsl #0x10
    add r0, ip, r0, lsr #0x10
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r0, r0, lsl #0x10
    mov r0, r0, asr #0x10
    mov r3, r0, lsl #0x10
    ldr r0, [r4, #0x14]
    mov r2, r1
    mov r3, r3, asr #0x10
    strh ip, [sp, #0x2]
    strh ip, [sp, #0x0]
    str r1, [sp, #0x4]
    str r1, [sp, #0x8]
    bl func_0201a934
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
