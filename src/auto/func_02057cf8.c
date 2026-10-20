#include "m2c.h"

void func_02001990(s32, s32);

// clang-format off
asm void func_02057cf8(s32 a0, s32 *obj, s32 sel, s32 flag) {
    stmdb sp!, {r3, lr}
    cmp r2, #0x0
    beq L_02057d18
    cmp r2, #0x1
    beq L_02057d2c
    cmp r2, #0x2
    beq L_02057d48
    ldmia sp!, {r3, pc}
L_02057d18:
    mov r0, r1
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x14]
    blx r1
    ldmia sp!, {r3, pc}
L_02057d2c:
    ldr r0, [r1, #0x8]
    cmp r3, #0x1
    orreq r0, r0, #0x1
    streq r0, [r1, #0x8]
    bicne r0, r0, #0x1
    strne r0, [r1, #0x8]
    ldmia sp!, {r3, pc}
L_02057d48:
    cmp r3, #0x0
    movne r2, #0x1
    moveq r2, #0x0
    mov r0, r1
    mov r1, r2
    bl func_02001990
    ldmia sp!, {r3, pc}
}
// clang-format on
