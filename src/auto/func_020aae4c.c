#include "m2c.h"

extern s32 data_027e02a8;
extern s32 *data_021092f4;

// clang-format off
asm void func_020aae4c(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r4, lr}
    ldr r3, =data_027e02a8
    mov r4, r0
    ldr r0, [r3, #0x0]
    tst r0, #0x40
    beq L_020aae88
    ldr r0, =data_021092f4
    mov r1, r2
    ldr r0, [r0, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x0]
    blx r2
    ldrh r0, [r0, #0x6a]
    strh r0, [r4, #0x0]
    ldmia sp!, {r4, pc}
L_020aae88:
    cmp r2, #0x0
    ldreqh r0, [r1, #0x42]
    streqh r0, [r4, #0x0]
    movne r0, #0x0
    strneh r0, [r4, #0x0]
    ldmia sp!, {r4, pc}
}
// clang-format on
