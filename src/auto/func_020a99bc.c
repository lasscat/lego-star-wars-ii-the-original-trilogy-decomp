#include "m2c.h"

extern u32 data_027e02a8[];
extern u32 data_021027f8[];
extern u32 data_0210794c[];

extern void func_020b04f0(s32, s32, s32, s32);

// clang-format off
asm void func_020a99bc(s32 a0, s32 a1) {
    stmdb sp!, {lr}
    sub sp, sp, #0x1c
    ldr r2, =data_027e02a8
    ldr r2, [r2, #0x0]
    tst r2, #0x40
    beq L_020a9a00
    ldr r0, =data_021027f8
    strb r1, [sp, #0x1]
    ldrb ip, [r0, #0x2a]
    ldr r0, =data_0210794c
    add r2, sp, #0x0
    mov r1, #0x39
    mov r3, #0xff
    strb ip, [sp, #0x0]
    bl func_020b04f0
    add sp, sp, #0x1c
    ldmia sp!, {pc}
L_020a9a00:
    ldr r2, =data_021027f8
    ldrb r2, [r2, #0x2a]
    add r0, r0, r2
    strb r1, [r0, #0x208]
    add sp, sp, #0x1c
    ldmia sp!, {pc}
}
// clang-format on
