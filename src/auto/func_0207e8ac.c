#include "m2c.h"

extern u32 data_020eff10[];
extern u32 data_020ef57c[];
extern u32 data_02104d5c[];

extern s32 func_02068e34(s32, s32, s32, s32);

// clang-format off
asm void func_0207e8ac(s32 a0) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    mov r7, #0x0
    ldr r9, =data_020eff10
    ldr r11, =data_020ef57c
    ldr r4, =data_02104d5c
    mov r10, r0
    mov r6, #0x1
    mov r8, #0x5
    mov r5, r7
L_0207e8d4:
    add r0, r4, r7, lsl #0x2
    ldr r2, [r0, #0x8]
    mov r1, r5
    cmp r2, #0x64
    bhs L_0207e93c
    mov r0, #0x18
    mla r0, r2, r0, r11
    ldr r1, [r10, #0x10]
    add r0, r0, #0x8
    str r1, [sp, #0x0]
    stmib sp, {r0, r5}
    mov r3, r8, lsl #0x10
    ldrsh r1, [r9, #0x6]
    ldrsh r2, [r9, #0x8]
    mov r0, r6
    mov r3, r3, lsr #0x10
    add r8, r8, #0x1
    bl func_02068e34
    ldr r2, [r10, #0x14]
    add r6, r6, r0
    ldr r2, [r2, r7, lsl #0x2]
    mov r1, #0x1
    ldr r0, [r2, #0x14]
    bic r0, r0, #0xf000
    orr r0, r0, #0xf000
    str r0, [r2, #0x14]
L_0207e93c:
    ldr r0, [r10, #0x14]
    cmp r1, #0x0
    ldr r1, [r0, r7, lsl #0x2]
    add r7, r7, #0x1
    ldr r0, [r1, #0x8]
    add r9, r9, #0xc
    orrne r0, r0, #0x1
    biceq r0, r0, #0x1
    str r0, [r1, #0x8]
    cmp r7, #0x8
    blo L_0207e8d4
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
