#include "m2c.h"

void func_0205d6f8(s32 *, s32);
void func_0205569c(s32 *);

// clang-format off
asm void func_02060fe4(s32 *arg0) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x18
    mov r4, r0
    mov r1, #0xa
    bl func_0205d6f8
    add r0, r4, #0x38
    mov r1, #0xa
    bl func_0205d6f8
    add r0, r4, #0x70
    bl func_0205569c
    ldr r0, =0x38e
    mov lr, #0x0
    str lr, [r4, #0x494]
    str lr, [r4, #0x4a0]
    str lr, [r4, #0x4a4]
    strh r0, [sp, #0xa]
    str lr, [r4, #0x4a8]
    ldrh ip, [sp, #0xa]
    strh r0, [sp, #0x8]
    strh r0, [sp, #0x6]
    str lr, [r4, #0x4b0]
    ldrh r3, [sp, #0x8]
    str lr, [r4, #0x4b4]
    ldrh r2, [sp, #0x6]
    str lr, [r4, #0x4b8]
    add r0, r4, #0x400
    strh ip, [r0, #0x98]
    strh r3, [r0, #0x9a]
    strh r2, [r0, #0x9c]
    mov r0, #0x1
    strb r0, [r4, #0x4ac]
    add r1, sp, #0xc
    add r0, r4, #0x4b0
    strh ip, [sp, #0x4]
    strh r3, [sp, #0x2]
    strh r2, [sp, #0x0]
    str lr, [sp, #0xc]
    str lr, [sp, #0x10]
    str lr, [sp, #0x14]
    cmp r0, r1
    beq L_0206109c
    str lr, [r4, #0x4b0]
    ldr r0, [r1, #0x4]
    str r0, [r4, #0x4b4]
    ldr r0, [r1, #0x8]
    str r0, [r4, #0x4b8]
L_0206109c:
    mov r0, #0x0
    strb r0, [r4, #0x4bc]
    mov r1, #0x10
    mov r0, r4
    str r1, [r4, #0x4c0]
    add sp, sp, #0x18
    ldmia sp!, {r4, pc}
}
// clang-format on
