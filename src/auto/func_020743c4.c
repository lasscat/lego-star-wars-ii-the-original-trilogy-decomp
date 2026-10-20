#include "m2c.h"

void func_0206574c(s32, s32, s32);
s32 func_02066708(s32);
void func_02065be8(s32, s32, s32, s32);
void func_02064b3c(s32, s32, s32, s32);

// clang-format off
asm void func_020743c4(s32 *arg0, s32 arg1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    mov r10, r0
    mov r5, #0x1
    mov r9, r1
    add r8, r10, #0x74
    mov r6, #0x0
    mov r7, #0x38
    mvn r4, #0x1
    mov r11, r5
L_020743ec:
    cmp r6, r9
    add r0, r10, #0x40
    bne L_02074408
    mov r1, #0x3
    mov r2, r4
    bl func_0206574c
    b L_02074414
L_02074408:
    mov r1, #0x0
    mov r2, r4
    bl func_0206574c
L_02074414:
    add r0, r6, #0x3
    bl func_02066708
    stmia sp, {r0, r11}
    add r0, r10, #0x40
    mov r1, r5
    mov r2, #0x80
    mov r3, r7
    bl func_02065be8
    mov r5, r0
    ldrb r0, [r10, #0xaa]
    cmp r0, #0x0
    bne L_0207446c
    mov r0, #0x80
    strh r0, [sp, #0x8]
    strh r7, [sp, #0xa]
    mov r0, #0x1
    str r0, [sp, #0x0]
    mov r0, r8
    add r1, sp, #0x8
    add r2, r10, #0x40
    add r3, r6, #0x3
    bl func_02064b3c
L_0207446c:
    add r7, r7, #0x20
    add r8, r8, #0xc
    add r6, r6, #0x1
    cmp r6, #0x3
    blt L_020743ec
    mov r0, #0x1
    strb r0, [r10, #0xaa]
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
