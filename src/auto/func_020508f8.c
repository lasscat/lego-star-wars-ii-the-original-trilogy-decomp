#include "m2c.h"

void *func_0205e80c(s32, s32, s32);
void func_020accac(s32, s32, s32, s32, s32);
s32 func_020029c4(s32, s32, s32, s32, s32);
void func_020043f4(s32);

// clang-format off
asm void func_020508f8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, ...) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x60
    ldr lr, [sp, #0x78]
    ldr r5, =0xb60b60b7
    mov r8, lr, lsl #0x10
    smull r4, ip, r5, r8
    mov r7, r0
    mov r6, r1
    mov r1, #0x0
    mov r5, r2
    add ip, ip, lr, lsl #0x10
    mov r0, r8, lsr #0x1f
    add ip, r0, ip, asr #0x8
    ldr r0, =0x6f8
    mov r2, #0x4
    mov r4, r3
    strh r1, [sp, #0x4]
    strh ip, [sp, #0x6]
    strh r1, [sp, #0x8]
    bl func_0205e80c
    movs r8, r0
    beq L_02050994
    mov ip, #0x1000
    add r0, sp, #0x18
    add r2, sp, #0x4
    add r3, sp, #0xc
    mov r1, r6
    str ip, [sp, #0xc]
    str ip, [sp, #0x10]
    str ip, [sp, #0x14]
    bl func_020accac
    add r6, sp, #0x18
    mov r0, r8
    mov r2, r7
    mov r1, #0x2
    mov r3, #0x0
    str r6, [sp, #0x0]
    bl func_020029c4
    mov r8, r0
L_02050994:
    strb r5, [r8, #0x6bc]
    mov r0, r8
    strb r4, [r8, #0x6bd]
    bl func_020043f4
    mov r0, r8
    add sp, sp, #0x60
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
