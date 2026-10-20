#include "m2c.h"

extern u32 data_02102900[];

extern s32 func_020aaea8(void);
extern s32 func_0200aef8(s32 a0, s32 a1, s32 a2);
extern void func_0200fc60(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200fb9c(s32 a0) {
    stmfd sp!, {r4, r5, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x8
    ldr r1, =data_02102900
    ldr r1, [r1, #0x0]
    cmp r1, #0x0
    ldrne r1, [r1, #0x4]
    moveq r1, #0x0
    cmp r1, #0x4
    addne sp, sp, #0x8
    ldmneia sp!, {r4, r5, r7, r8, r9, r10, r11, pc}
    ldr r8, [r0, #0x4]
    cmp r8, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r4, r5, r7, r8, r9, r10, r11, pc}
    ldr r11, =0x304001
    mov r7, #0x64000
    sub r4, r11, #0x200000
    mov r5, #0x1000
L_0200fbe4:
    ldr r9, [r8, #0x0]
    ldr r0, [r9, #0x8]
    and r0, r0, r11
    cmp r0, r4
    bne L_0200fc44
    add r0, r9, #0x100
    ldrh r0, [r0, #0xa8]
    mov r10, #0x1
    tst r0, #0x8
    bne L_0200fc2c
    str r7, [sp, #0x4]
    bl func_020aaea8
    add r1, r0, #0x28
    add r0, r9, #0xb0
    mov r2, r7
    bl func_0200aef8
    cmp r0, #0x0
    movne r10, #0x0
L_0200fc2c:
    cmp r10, #0x0
    bne L_0200fc44
    mov r1, r5
    add r0, r9, #0xb0
    str r5, [sp, #0x0]
    bl func_0200fc60
L_0200fc44:
    ldr r8, [r8, #0x4]
    cmp r8, #0x0
    bne L_0200fbe4
    add sp, sp, #0x8
    ldmia sp!, {r4, r5, r7, r8, r9, r10, r11, pc}
}
// clang-format on
