#include "m2c.h"

extern void func_0209f948(s32, s32);

// clang-format off
asm void func_0201e6dc(s32 a0, s32 a1) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x8
    cmp r1, #0x3
    mov r4, r0
    addne sp, sp, #0x8
    ldmneia sp!, {r4, pc}
    mov r1, #0x3
    strb r1, [r4, #0x1bc]
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x58
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx ip
    ldr r0, [r4, #0x148]
    cmp r0, #0x0
    moveq r0, #0x0
    beq L_0201e734
    ldr r0, [r0, #0x8]
    ldrh r0, [r0, #0x4]
    mov r0, r0, lsl #0xc
L_0201e734:
    sub r1, r0, #0x1000
    add r0, r4, #0xd4
    str r1, [sp, #0x4]
    bl func_0209f948
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
}
// clang-format on
