#include "m2c.h"

extern u32 data_020ed2eb[];

extern void func_02046bb8(s32 a0, s32 a1);
extern s32 func_0208e190(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02046b24(s32 a0) {
    stmfd sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov r1, #0x1
    bl func_02046bb8
    ldrb r0, [r4, #0xe]
    cmp r0, #0x0
    beq L_02046ba4
    mov r0, #0x5
    strb r0, [r4, #0xd]
    ldr r0, [r4, #0x4]
    bl func_0208e190
    strb r0, [r4, #0x16]
    mov r0, #0x1
    strb r0, [r4, #0x1b]
    ldrb r0, [r4, #0x16]
    ldr r1, =data_020ed2eb
    mov r2, #0x1
    cmp r0, #0x7
    moveq r0, #0x1b
    streqb r0, [r4, #0x16]
    mov r0, #0x0
    str r0, [sp, #0x0]
    ldrb r3, [r4, #0x16]
    ldr r0, [r4, #0x4]
    ldr r4, [r0, #0x0]
    ldrb r1, [r1, r3, lsl #0x4]
    ldr r4, [r4, #0x24]
    mov r3, r2
    blx r4
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
L_02046ba4:
    mov r0, #0x0
    strb r0, [r4, #0xd]
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
