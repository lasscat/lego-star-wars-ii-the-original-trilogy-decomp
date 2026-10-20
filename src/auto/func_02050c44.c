#include "m2c.h"

extern u32 data_02104d90[];
extern u32 data_0210930c[];

extern s32 func_02086204(s32 a0, s32 a1);
extern void func_02091b88(s32 a0, s32 a1, s32 a2, s32 a3);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02050c44(s32 a0) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x10
    mov r4, r0
    ldrsh r2, [r4, #0x4]
    ldrsh r1, [r4, #0x2]
    ldrsh r0, [r4, #0x0]
    mov r3, r2, lsl #0xc
    mov r2, r1, lsl #0xc
    mov r1, r0, lsl #0xc
    ldr r0, =data_02104d90
    str r1, [sp, #0x4]
    str r2, [sp, #0x8]
    str r3, [sp, #0xc]
    mov r1, #0xa
    ldrb r5, [r4, #0x8]
    bl func_02086204
    cmp r0, #0x0
    beq L_02050cc4
    mov r2, #0x0
    ldr r1, =data_0210930c
    mov r3, r2
L_02050c98:
    add r0, r1, r3, lsl #0x2
    ldr r0, [r0, #0x4c]
    add r3, r3, #0x1
    cmp r0, #0x0
    addne r2, r2, #0x1
    cmp r3, #0x4
    blo L_02050c98
    cmp r2, #0x2
    addhs sp, sp, #0x10
    movhs r0, #0x0
    ldmhsia sp!, {r3, r4, r5, pc}
L_02050cc4:
    mov r0, #0x1
    str r0, [sp, #0x0]
    ldrb r1, [r4, #0x9]
    ldr r0, =data_0210930c
    add r3, sp, #0x4
    mov r2, r5
    bl func_02091b88
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
