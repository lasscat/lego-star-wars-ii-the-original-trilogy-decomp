#include "m2c.h"

extern u32 data_020f4910[];
extern void func_020865ac();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02086ea0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r6, r1
    add r0, r7, #0x520
    and r4, r6, #0x1f
    mov ip, #0x1
    add r2, r0, #0x4000
    mov r3, r6, asr #0x5
    mvn r0, ip, lsl r4
    ldr r1, [r2, r3, lsl #0x2]
    mov r5, #0x0
    and r1, r1, r0
    orr r0, r1, ip, lsl r4
    ldr     r4, =data_020f4910
    str r0, [r2, r3, lsl #0x2]
    L_02086edc:
    ldrb r0, [r4, r5, lsl #0x2]
    mov r1, r5, lsl #0x2
    cmp r0, #0x4
    addeq r0, r4, r1
    ldreqsh r0, [r0, #0x2]
    cmpeq r6, r0
    bne      L_02086f04
    mov r0, r7
    mov r1, r5
    bl      func_020865ac
    L_02086f04:
    add r0, r5, #0x1
    mov r0, r0, lsl #0x10
    mov r5, r0, lsr #0x10
    cmp r5, #0xfa
    blo      L_02086edc
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
