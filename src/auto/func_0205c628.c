#include "m2c.h"

extern void func_01ffa478(s32, s32);

// clang-format off
asm void func_0205c628(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    movs r4, r1
    mov r5, r0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    mov r7, #0x0
    mov r6, r7
L_0205c640:
    ldr r0, [r5, r7, lsl #0x2]
    cmp r0, #0x0
    beq L_0205c68c
    mov r1, r6
    bl func_01ffa478
    ldrb r1, [r0, #0xf]
    cmp r1, #0x0
    bne L_0205c68c
    add r1, r5, #0x1c
    cmp r1, r0
    beq L_0205c684
    ldr r1, [r0, #0x0]
    str r1, [r5, #0x1c]
    ldr r1, [r0, #0x4]
    str r1, [r5, #0x20]
    ldr r0, [r0, #0x8]
    str r0, [r5, #0x24]
L_0205c684:
    strb r4, [r5, #0x2f]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_0205c68c:
    add r7, r7, #0x1
    cmp r7, #0x7
    blt L_0205c640
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
