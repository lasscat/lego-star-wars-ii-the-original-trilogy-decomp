#include "m2c.h"

extern void func_020534e0(s32 a0);
extern void func_02067bc0(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0206b74c(s32 a0) {
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    mov r4, r0
    mov r7, r4
    add r5, r4, #0x40
    mov r6, #0x0
L_0206b760:
    str r6, [r7, #0x4]
    add r0, r7, #0xc
    str r6, [r7, #0x8]
    bl func_020534e0
    add r7, r7, #0x20
    cmp r7, r5
    blo L_0206b760
    mov r1, #0x0
    str r1, [r4, #0x40]
    str r1, [r4, #0x44]
    add r0, r4, #0x4c
    str r1, [r4, #0x48]
    bl func_02067bc0
    add r0, r4, #0x54
    bl func_020534e0
    mov r0, #0x2
    str r0, [r4, #0x5c]
    sub r0, r0, #0x3
    str r0, [r4, #0x60]
    mov r0, #0xa0
    str r0, [r4, #0x70]
    mov r3, #0x0
    bic r1, r3, #0x1
    add r0, r4, #0x800
    mov r2, #0x6
    strh r2, [r0, #0x84]
    strh r3, [r0, #0x88]
    strh r3, [r0, #0x8a]
    orr r1, r1, #0x1
    strh r1, [r0, #0x80]
    mov r2, r3
L_0206b7dc:
    str r2, [r4, r3, lsl #0x5]
    add r1, r4, r3, lsl #0x5
    strh r2, [r1, #0x14]
    strh r2, [r1, #0x16]
    strh r2, [r1, #0x18]
    strh r2, [r1, #0x1c]
    ldrh r0, [r1, #0x1c]
    add r3, r3, #0x1
    cmp r3, #0x2
    strh r0, [r1, #0x1a]
    blo L_0206b7dc
    mov r0, r4
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
