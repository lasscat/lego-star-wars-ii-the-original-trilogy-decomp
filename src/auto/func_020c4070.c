#include "m2c.h"

extern s32 func_020c3e84(s32, s32);
extern s32 func_020c3fc4(s32, s32);

// clang-format off
asm s32 func_020c4070(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r8, r0
    ldrb r0, [r8, #0x9]
    mov r7, r1
    mov r6, #0x1
    cmp r0, #0x0
    mov r5, #0x0
    bls L_020c40d8
    add r4, r8, #0x8
L_020c4094:
    ldrh r0, [r8, #0xe]
    mov r1, r7
    ldrh r2, [r4, r0]
    add r0, r4, r0
    mla r0, r2, r5, r0
    ldr r9, [r0, #0x4]
    add r0, r8, r9
    bl func_020c3e84
    and r6, r6, r0
    mov r1, r7
    add r0, r8, r9
    bl func_020c3fc4
    ldrb r1, [r8, #0x9]
    add r5, r5, #0x1
    and r6, r6, r0
    cmp r5, r1
    blo L_020c4094
L_020c40d8:
    mov r0, r6
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
