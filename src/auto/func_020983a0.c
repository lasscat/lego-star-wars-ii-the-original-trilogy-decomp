#include "m2c.h"

extern M2C_UNK data_027e02a8[];
extern M2C_UNK data_0210794c[];

void func_020b04f0(s32, s32, s32, s32, s32);

// clang-format off
asm void func_020983a0(s32 *a0, s32 *a1) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x1c
    ldr r2, =data_027e02a8
    mov r4, r0
    ldr r0, [r2, #0x0]
    tst r0, #0x40
    beq L_02098404
    mov r0, r1
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx r1
    str r0, [sp, #0x0]
    ldr r1, [r4, #0x4]
    ldr r0, =data_0210794c
    str r1, [sp, #0x4]
    ldr r1, [r4, #0x8]
    add r2, sp, #0x0
    str r1, [sp, #0x8]
    ldr r4, [r4, #0xc]
    mov r1, #0x38
    mov r3, #0xff
    str r4, [sp, #0xc]
    bl func_020b04f0
    add sp, sp, #0x1c
    ldmia sp!, {r3, r4, pc}
L_02098404:
    add r2, r1, #0x6a0
    add r0, r4, #0x4
    cmp r2, r0
    addeq sp, sp, #0x1c
    ldmeqia sp!, {r3, r4, pc}
    ldr r0, [r4, #0x4]
    str r0, [r1, #0x6a0]
    ldr r0, [r4, #0x8]
    str r0, [r1, #0x6a4]
    ldr r0, [r4, #0xc]
    str r0, [r1, #0x6a8]
    add sp, sp, #0x1c
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
