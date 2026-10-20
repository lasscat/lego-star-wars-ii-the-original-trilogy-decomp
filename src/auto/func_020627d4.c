#include "m2c.h"

// clang-format off
asm void func_020627d4(s32 a0, s32 a1) {
    stmdb sp!, {r4, lr}
    mov r2, #0x38
    mla r0, r1, r2, r0
    ldr r4, [r0, #0x4]
    cmp r4, #0x0
    ldmeqia sp!, {r4, pc}
L_020627ec:
    ldmia r4, {r0, r4}
    ldrb r1, [r0, #0x4]
    cmp r1, #0x0
    beq L_02062808
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
L_02062808:
    cmp r4, #0x0
    bne L_020627ec
    ldmia sp!, {r4, pc}
}
// clang-format on
