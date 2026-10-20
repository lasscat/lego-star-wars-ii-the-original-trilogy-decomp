#include "m2c.h"

extern s32 func_020bd700(void);
extern s32 func_020bd940(s32, s32);

// clang-format off
asm s32 func_020bdad8(s32 a0) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    bl func_020bd700
    ldr r1, [r0, #0x0]
    add r4, r0, #0xc
    str r1, [r7, #0x68]
    ldr r1, [r0, #0x4]
    add r6, r7, #0x48
    str r1, [r7, #0x6c]
    ldr r0, [r0, #0x8]
    mov r5, #0x0
    str r0, [r7, #0x70]
L_020bdb08:
    mov r0, r6
    mov r1, r4
    bl func_020bd940
    add r5, r5, #0x1
    mov r4, r0
    cmp r5, #0x3
    add r6, r6, #0x8
    blt L_020bdb08
    mov r0, r7
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    add r0, r4, #0x2
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
