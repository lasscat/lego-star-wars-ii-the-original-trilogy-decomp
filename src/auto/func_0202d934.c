#include "m2c.h"

extern s32 func_0205e80c(s32, s32, s32);
extern s32 func_02032b44(s32, s32, s32, s32, s32, s32);
extern void func_0202c1a8(s32, s32);

// clang-format off
asm s32 func_0202d934(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x18
    mov r8, r0
    mov r7, r1
    mov r6, r2
    mov r0, #0x40
    mov r1, #0x1
    mov r2, #0x4
    mov r5, r3
    bl func_0205e80c
    movs r4, r0
    beq L_0202d994
    mov r1, #0x0
    str r1, [sp, #0x0]
    stmib sp, {r1, r6}
    mov r3, #0x2000
    ldr ip, [sp, #0x30]
    str r5, [sp, #0xc]
    mov r1, r8
    mov r2, r7
    str r3, [sp, #0x14]
    str ip, [sp, #0x10]
    bl func_02032b44
    mov r4, r0
L_0202d994:
    mov r1, r4
    add r0, r8, #0x5e0
    bl func_0202c1a8
    mov r0, r4
    add sp, sp, #0x18
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
