#include "m2c.h"

s32 func_020abdc0(s32);
void func_020abd50(s32);
void func_0205e84c(s32);

// clang-format off
asm s32 func_020abeac(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, lr}
    movs r4, r1
    mov r5, r0
    beq L_020abf00
    mov r0, r4
    bl func_020abdc0
    cmp r0, #0x0
    beq L_020abf00
    mov r0, r5
    ldr r2, [r0, #0x0]
    mov r1, r4
    ldr r2, [r2, #0xc]
    blx r2
    cmp r4, #0x0
    beq L_020abef8
    mov r0, r4
    bl func_020abd50
    mov r0, r4
    bl func_0205e84c
L_020abef8:
    mov r0, #0x1
    ldmia sp!, {r3, r4, r5, pc}
L_020abf00:
    mov r0, #0x0
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
