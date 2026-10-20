#include "m2c.h"

extern s32 func_020bd700(s32 a0);
extern s32 func_020bd940(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bdf38(s32 a0) {
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    mov r4, r0
    bl func_020bd700
    ldr r1, [r0, #0x0]
    add r5, r0, #0x10
    str r1, [r4, #0x68]
    ldr r1, [r0, #0x4]
    add r7, r4, #0x48
    str r1, [r4, #0x6c]
    ldr r1, [r0, #0x8]
    mov r6, #0x0
    str r1, [r4, #0x70]
    ldr r0, [r0, #0xc]
    str r0, [r4, #0x74]
L_020bdf70:
    mov r0, r7
    mov r1, r5
    bl func_020bd940
    add r6, r6, #0x1
    mov r5, r0
    cmp r6, #0x3
    add r7, r7, #0x8
    blt L_020bdf70
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    mov r0, r5
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
