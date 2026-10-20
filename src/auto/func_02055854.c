#include "m2c.h"

void func_0205e068(s32);
void func_0205e084(s32, s32);

// clang-format off
asm void func_02055854(s32 *a0, s32 *a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r1
    ldr r4, [r6, #0x28]
    mov r2, #0x0
    mov r7, r0
    mov r5, r2
    cmp r4, #0x0
    beq L_020558cc
L_02055874:
    ldr r1, [r4, #0x0]
    ldr r3, [r1, #0x8]
    tst r3, #0x80000000
    beq L_02055894
    ldr r2, [r1, #0x4]
    bic r0, r3, #0x80000000
    str r2, [r0, #0x0]
    b L_020558a4
L_02055894:
    cmp r3, #0x0
    ldrne r0, [r1, #0x4]
    strne r0, [r3, #0x4]
    ldr r2, [r1, #0x4]
L_020558a4:
    cmp r2, #0x0
    ldrne r0, [r1, #0x8]
    strne r0, [r2, #0x8]
    mov r0, r7
    bl func_0205e068
    mov r2, r4
    ldr r4, [r4, #0x4]
    add r5, r5, #0x1
    cmp r4, #0x0
    bne L_02055874
L_020558cc:
    ldr r1, [r6, #0x28]
    cmp r1, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r7
    mov r3, r5
    bl func_0205e084
    mov r0, #0x0
    str r0, [r6, #0x28]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
