#include "m2c.h"

void func_020985d8(s32, s32, s32, s32, s32, s32);

// clang-format off
asm void func_02029068(s32 *out, s32 *in, s32 *arg) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x18
    cmp r1, #0x0
    mov r4, r0
    moveq r0, #0x0
    addeq r1, sp, #0x0
    streqh r0, [sp, #0x0]
    beq L_020290d0
    ldr r3, [r2, #0x8]
    ldr r0, [r1, #0xb8]
    ldr ip, [r2, #0x4]
    sub lr, r3, r0
    ldr r3, [r1, #0xb4]
    ldr r0, [r1, #0xb0]
    ldr r1, [r2, #0x0]
    sub r2, ip, r3
    sub r0, r1, r0
    mov r1, lr
    str r0, [sp, #0xc]
    str r2, [sp, #0x10]
    str lr, [sp, #0x14]
    str lr, [sp, #0x8]
    str r0, [sp, #0x4]
    bl func_020985d8
    strh r0, [sp, #0x2]
    add r1, sp, #0x2
L_020290d0:
    ldrh r0, [r1, #0x0]
    strh r0, [r4, #0x0]
    add sp, sp, #0x18
    ldmia sp!, {r4, pc}
}
// clang-format on
