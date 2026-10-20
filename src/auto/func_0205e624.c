#include "m2c.h"

extern void MIi_CpuClearFast(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205e624(s32 a0, s32 a1, s32 a2) {
    stmfd sp!, {r3, r4, r5, lr}
    mov r4, r0
    mov r0, r1
    orr r0, r0, r0, lsl #0x8
    tst r4, #0x3
    orr r0, r0, r0, lsl #0x10
    bne L_0205e654
    tst r2, #0x3
    bne L_0205e654
    mov r1, r4
    bl MIi_CpuClearFast
    b L_0205e6d8
L_0205e654:
    and r3, r4, #0x3
    rsb r5, r3, #0x4
    mov ip, r4
    cmp r5, #0x4
    beq L_0205e698
    cmp r2, r5
    movlo r5, r2
    cmp r5, #0x0
    mov lr, #0x0
    bls L_0205e690
    and r3, r1, #0xff
L_0205e680:
    strb r3, [ip, lr]
    add lr, lr, #0x1
    cmp lr, r5
    blo L_0205e680
L_0205e690:
    sub r2, r2, lr
    add ip, ip, lr
L_0205e698:
    movs r3, r2, lsr #0x2
    mov r5, #0x0
    beq L_0205e6b4
L_0205e6a4:
    str r0, [ip, r5, lsl #0x2]
    add r5, r5, #0x1
    cmp r5, r3
    blo L_0205e6a4
L_0205e6b4:
    add ip, ip, r5, lsl #0x2
    ands r2, r2, #0x3
    mov r3, #0x0
    beq L_0205e6d8
    and r0, r1, #0xff
L_0205e6c8:
    strb r0, [ip, r3]
    add r3, r3, #0x1
    cmp r3, r2
    blo L_0205e6c8
L_0205e6d8:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
