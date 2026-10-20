#include "m2c.h"

extern void func_020140f8(s32 a0);
extern s32 func_02015138(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02026e7c(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    ldr r1, [r1, #0x0]
    mov r4, r0
    ldrh r0, [r1, #0xc]
    cmp r0, #0x1
    cmpne r0, #0x10
    ldmneia sp!, {r3, r4, r5, pc}
    cmp r4, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, r4
    bl func_020140f8
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx r1
    ldr r2, [r4, #0x8]
    add r1, r4, #0x200
    orr r2, r2, #0x2
    str r2, [r4, #0x8]
    mov r5, r0
    ldrh r0, [r1, #0x12]
    add r2, r4, #0x8c
    mov r1, #0x0
    cmp r0, #0x5d
    bne L_02026eec
    mov r0, #0x5c
    bl func_02015138
    b L_02026ef0
L_02026eec:
    bl func_02015138
L_02026ef0:
    mvn r1, #0x0
    cmp r5, r1
    strne r5, [r0, #0x1b4]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
