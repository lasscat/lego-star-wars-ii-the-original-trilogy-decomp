#include "m2c.h"

extern u32 data_02104434[];

extern void func_02063cc4(s32 a0);
extern void func_020b973c(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02063da0(s32 a0) {
    stmfd sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x1d]
    cmp r1, #0x0
    beq L_02063dc0
    ldr r0, =data_02104434
    bl func_02063cc4
    b L_02063dd8
L_02063dc0:
    ldr r0, [r4, #0x0]
    cmp r0, #0x0
    beq L_02063dd8
    bl func_020b973c
    mov r0, #0x0
    str r0, [r4, #0x0]
L_02063dd8:
    ldr r0, =data_02104434
    mov r1, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0xc]
    blx r2
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
