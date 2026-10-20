#include "m2c.h"

extern u32 data_020f0258[];

void func_02054c80(s32, s32, s32, s32);

// clang-format off
asm void func_020885a4(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x48
    ldr r6, =data_020f0258
    add lr, sp, #0x28
    mov ip, #0xf
L_020885b8:
    ldrb r5, [r6, #0x0]
    ldrb r4, [r6, #0x1]
    add r6, r6, #0x2
    strb r5, [lr, #0x0]
    strb r4, [lr, #0x1]
    add lr, lr, #0x2
    subs ip, ip, #0x1
    bne L_020885b8
    mov ip, #0x6
    mul r5, r2, ip
    add r4, sp, #0x28
    add r2, sp, #0x29
    add r4, r4, r5
    add r2, r2, r5
    ldrb lr, [r2, r3, lsl #0x1]
    ldrb r4, [r4, r3, lsl #0x1]
    add r1, r0, r1
    ldrb r3, [r1, #0x11]
    mov r2, #0x12
    mov r1, #0x5a
    strh r3, [sp, #0x1c]
    strh r2, [sp, #0x1e]
    str r1, [sp, #0x0]
    mov r2, #0x0
    str r2, [sp, #0x4]
    str r2, [sp, #0x8]
    str r2, [sp, #0xc]
    add r1, sp, #0x1c
    str r1, [sp, #0x10]
    strb r4, [sp, #0x14]
    strb lr, [sp, #0x15]
    mov r5, #0x5
    strb ip, [sp, #0x16]
    strb r5, [sp, #0x17]
    ldr r1, [r0, #0x0]
    ldr r2, =0x593
    add r0, sp, #0x20
    mov r3, #0xd
    strb r4, [sp, #0x18]
    strb lr, [sp, #0x19]
    strb ip, [sp, #0x1a]
    strb r5, [sp, #0x1b]
    bl func_02054c80
    add sp, sp, #0x48
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
