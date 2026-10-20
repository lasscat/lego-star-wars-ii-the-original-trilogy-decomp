#include "m2c.h"

extern u32 data_0210930c[];

extern void func_0205d6f8(s32 a0, s32 a1);
extern void func_0205d72c(s32 a0);
extern void func_020903f0(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020679f0(s32 a0) {
    stmfd sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x38
    mov r6, r0
    add r0, sp, #0x0
    mov r1, #0xa
    bl func_0205d6f8
    ldrb r0, [r6, #0x5]
    mov r5, #0x0
    cmp r0, #0x0
    bls L_02067a4c
    add r4, sp, #0x0
L_02067a1c:
    ldr r0, [r6, #0x0]
    ldr r1, [r0, r5, lsl #0x3]
    cmp r1, #0x0
    beq L_02067a3c
    mov r0, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x8]
    blx r2
L_02067a3c:
    ldrb r0, [r6, #0x5]
    add r5, r5, #0x1
    cmp r5, r0
    blo L_02067a1c
L_02067a4c:
    ldrh r0, [sp, #0xc]
    cmp r0, #0x0
    beq L_02067a6c
    ldr r0, =data_0210930c
    add r1, sp, #0x0
    ldr r0, [r0, #0x68]
    mov r2, #0x0
    bl func_020903f0
L_02067a6c:
    add r0, sp, #0x0
    bl func_0205d72c
    add sp, sp, #0x38
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
