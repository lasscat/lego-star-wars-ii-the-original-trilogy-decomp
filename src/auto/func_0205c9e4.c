#include "m2c.h"

extern u32 data_020fcd18[];
extern u32 data_020fe4a8[];

void *func_0205e824(s32);
void func_0200af88(void *, s32);
void func_0205ca98(s32, s32, s32);

// clang-format off
asm void func_0205c9e4(s32 *arg0, s32 *arg1, s32 arg2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r1
    ldrb r1, [r7, #0xf]
    mov r8, r0
    mov r6, r2
    sub r4, r1, #0x2
    ldr r0, [r8, r4, lsl #0x2]
    cmp r0, #0x0
    bne L_0205ca7c
    mov r0, #0x34
    bl func_0205e824
    movs r5, r0
    beq L_0205ca78
    ldr r0, =data_020fcd18
    mov r2, #0x0
    stmia r5, {r0, r2}
    str r2, [r5, #0x8]
    str r2, [r5, #0xc]
    str r2, [r5, #0x10]
    str r2, [r5, #0x14]
    str r2, [r5, #0x18]
    str r2, [r5, #0x1c]
    add r0, r5, #0x24
    sub r1, r2, #0x1
    str r2, [r5, #0x20]
    bl func_0200af88
    mvn r0, #0x0
    strb r0, [r5, #0x25]
    mov r1, #0x0
    ldr r0, =data_020fe4a8
    strb r1, [r5, #0x26]
    str r0, [r5, #0x0]
    strh r1, [r5, #0x28]
    strh r1, [r5, #0x2a]
    strh r1, [r5, #0x2c]
    str r1, [r5, #0x30]
    strb r1, [r5, #0x25]
L_0205ca78:
    str r5, [r8, r4, lsl #0x2]
L_0205ca7c:
    mov r0, r8
    mov r1, r7
    mov r2, r6
    bl func_0205ca98
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
