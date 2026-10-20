#include "m2c.h"

void func_0205d4c8(s32, s32);
void func_0205e84c(s32);

// clang-format off
asm void func_0207f504(s32 *arg0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    ldr r5, [r6, #0xc]
    cmp r5, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
L_0207f518:
    ldr r4, [r5, #0x0]
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    cmp r0, #0x0
    beq L_0207f55c
    mov r1, r5
    add r0, r6, #0x8
    ldr r5, [r5, #0x8]
    bl func_0205d4c8
    mov r0, r4
    bl func_0205e84c
    cmp r5, #0x0
    bne L_0207f55c
    ldr r5, [r6, #0xc]
    b L_0207f560
L_0207f55c:
    ldr r5, [r5, #0x4]
L_0207f560:
    cmp r5, #0x0
    bne L_0207f518
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
