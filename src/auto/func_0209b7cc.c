#include "m2c.h"

void func_0205e624(s32, s32, s32);
void func_0209b6e4(s32, s32);

// clang-format off
asm void func_0209b7cc(s32 *arg0) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    mov r4, r0
    mov r2, #0x0
    add r1, sp, #0x0
    add r0, r4, #0x44
    str r2, [sp, #0x0]
    str r2, [sp, #0x4]
    str r2, [sp, #0x8]
    cmp r0, r1
    beq L_0209b80c
    str r2, [r4, #0x44]
    ldr r0, [r1, #0x4]
    str r0, [r4, #0x48]
    ldr r0, [r1, #0x8]
    str r0, [r4, #0x4c]
L_0209b80c:
    mov r0, #0x5
    mov r1, #0x0
    strb r0, [r4, #0x40]
    str r1, [r4, #0x34]
    sub r0, r1, #0x1
    strb r0, [r4, #0x41]
    strb r1, [r4, #0x42]
    strb r1, [r4, #0x50]
    strb r1, [r4, #0x6]
    str r1, [r4, #0x8]
    add r0, r4, #0x14
    mov r2, #0x8
    strh r1, [r4, #0xb2]
    bl func_0205e624
    add r0, r4, #0x1c
    mov r1, #0x0
    mov r2, #0x8
    bl func_0205e624
    add r0, r4, #0x24
    mov r1, #0x0
    mov r2, #0x8
    bl func_0205e624
    add r0, r4, #0x51
    mov r1, #0x0
    mov r2, #0x60
    bl func_0205e624
    mov r1, #0x12c
    mov r0, r4
    str r1, [r4, #0x3c]
    bl func_0209b6e4
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
