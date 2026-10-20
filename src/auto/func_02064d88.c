#include "m2c.h"

extern u32 data_021044fc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02064d88(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, lr}
    add r5, r0, r1
    cmp r0, r5
    ldmhsia sp!, {r3, r4, r5, pc}
    ldr r1, =data_021044fc
    mov r3, #0x1
    add r2, r1, r2, lsl #0x7
    mov ip, #0xff
L_02064da8:
    mov r4, r0, lsr #0x3
    ands lr, r0, #0x7
    bne L_02064dc8
    sub r1, r5, r0
    cmp r1, #0x8
    movhs lr, ip
    addhs r0, r0, #0x8
    bhs L_02064dd0
L_02064dc8:
    mov lr, r3, lsl lr
    add r0, r0, #0x1
L_02064dd0:
    ldrb r1, [r2, r4]
    cmp r0, r5
    orr r1, r1, lr
    strb r1, [r2, r4]
    blo L_02064da8
    ldmfd sp!, {r3, r4, r5, pc}
}
// clang-format on
