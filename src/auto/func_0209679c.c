#include "m2c.h"

// clang-format off
asm void func_0209679c(s32 *obj) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    ldr r6, [r9, #0x4]
    cmp r6, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r4, #0x0
    mov r5, #0x1
L_020967b8:
    ldr r8, [r6, #0x0]
    ldr r0, [r8, #0x28]
    and r0, r0, #0x1
    cmp r0, #0x1
    bne L_02096814
    ldr r0, [r9, #0x4]
    mov r7, r5
    cmp r6, r0
    mov r0, r9
    ldr r2, [r0, #0x0]
    mov r1, r8
    ldr r2, [r2, #0xc]
    ldrne r6, [r6, #0x8]
    movne r7, r4
    blx r2
    cmp r8, #0x0
    beq L_0209680c
    mov r0, r8
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0209680c:
    cmp r7, #0x0
    ldrne r6, [r9, #0x4]
L_02096814:
    cmp r6, #0x0
    ldrne r6, [r6, #0x4]
    cmp r6, #0x0
    bne L_020967b8
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
