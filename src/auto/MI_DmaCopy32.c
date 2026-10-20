#include "m2c.h"

void MIi_CheckDma0SourceAddress(s32, s32, s32, s32);
void func_01ffd4c8(s32, s32, s32, s32);

// clang-format off
asm void MI_DmaCopy32(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r5, r3
    mov r6, r2
    mov r2, r5
    mov r3, #0x0
    mov r8, r0
    mov r7, r1
    bl MIi_CheckDma0SourceAddress
    cmp r5, #0x0
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    add r0, r8, r8, lsl #0x1
    add r0, r0, #0x2
    mov r0, r0, lsl #0x2
    add r0, r0, #0xb0
    add r4, r0, #0x4000000
L_020ceb5c:
    ldr r0, [r4, #0x0]
    tst r0, #0x80000000
    bne L_020ceb5c
    mov r3, r5, lsr #0x2
    mov r0, r8
    mov r1, r7
    mov r2, r6
    orr r3, r3, #0x84000000
    bl func_01ffd4c8
L_020ceb80:
    ldr r0, [r4, #0x0]
    tst r0, #0x80000000
    bne L_020ceb80
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
