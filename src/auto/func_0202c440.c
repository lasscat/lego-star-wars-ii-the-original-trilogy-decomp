#include "m2c.h"

s32 func_0202f790(s32, s32);
void func_0202c698(s32, s32, s32);

// clang-format off
asm void func_0202c440(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r0, [r5, #0x18]
    mov r4, r1
    cmp r0, #0x0
    beq L_0202c464
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0202c464:
    mov r0, #0x0
    str r0, [r5, #0x18]
    cmp r4, #0x5
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r0, [r5, #0x20]
    mov r1, r4
    bl func_0202f790
    str r0, [r5, #0x18]
    mov r1, r0
    mov r0, r5
    mov r2, #0x1
    bl func_0202c698
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
