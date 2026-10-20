#include "m2c.h"

void func_01ffad38(s32, s32);
void func_0200c31c(s32, s32);
void func_02010384(s32, s32);

// clang-format off
asm void func_0200c28c(s32 *a0, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r6, r0
    mov r5, r6
    mov r4, #0x0
    add r9, sp, #0x24
    mov r7, #0x38
    mvn r8, #0x0
L_0200c2ac:
    add r1, r5, #0x100
    ldrsb r2, [r1, #0xe1]
    ldr r0, [r5, #0x1d0]
    cmp r0, #0x0
    cmpne r2, r8
    mlane r1, r2, r7, r6
    ldrneb r1, [r1, #0x3cc]
    cmpne r1, #0x0
    ldrneb r1, [r5, #0x1df]
    cmpne r1, #0x0
    beq L_0200c2f0
    ldr r1, [r9, #0x0]
    mov r2, r6
    bl func_01ffad38
    mov r0, r6
    mov r1, r4
    bl func_0200c31c
L_0200c2f0:
    add r4, r4, #0x1
    cmp r4, #0xc
    add r5, r5, #0x28
    blo L_0200c2ac
    add r1, sp, #0x24
    ldr r1, [r1, #0x0]
    mov r0, r6
    bl func_02010384
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
