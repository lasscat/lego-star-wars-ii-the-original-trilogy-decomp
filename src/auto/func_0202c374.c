#include "m2c.h"

extern void func_0202c710(s32, s32, s32, s32);

// clang-format off
asm void func_0202c374(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    ldr r5, [r7, #0x4]
    mov r6, r1
    cmp r5, #0x0
    subne r5, r5, #0x4
    mov r4, r5
    cmp r5, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
L_0202c398:
    mov r0, r7
    mov r1, r5
    mov r2, r4
    mov r3, r6
    bl func_0202c710
    ldr r1, [r4, #0x4]
    mov r4, r0
    ldr r0, [r1, #0x8]
    cmp r0, r6
    bne L_0202c3d4
    ldrb r2, [r1, #0xc]
    mov r0, r7
    orr r2, r2, #0x1
    strb r2, [r1, #0xc]
    bl func_0202c374
L_0202c3d4:
    cmp r4, #0x0
    bne L_0202c398
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
