#include "m2c.h"

extern void func_0205e860(s32 a0);
extern s32 func_020aaeb4(void);
extern void G3X_SetClearColor(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0200171c(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020818fc(s32 a0) {
    stmfd sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4
    mov r5, #0x0
    mov r6, r0
    mov r4, r5
L_02081910:
    add r0, r6, r5, lsl #0x2
    ldr r0, [r0, #0x134]
    cmp r0, #0x0
    beq L_02081924
    bl func_0205e860
L_02081924:
    add r0, r6, r5, lsl #0x2
    add r5, r5, #0x1
    str r4, [r0, #0x134]
    cmp r5, #0x5
    blt L_02081910
    ldr r0, [r6, #0x15c]
    cmp r0, #0x0
    beq L_02081948
    bl func_0205e860
L_02081948:
    mov r0, #0x0
    str r0, [r6, #0x15c]
    bl func_020aaeb4
    mov ip, #0x0
    strb ip, [r0, #0x1b0]
    ldr r1, [r0, #0x1ac]
    ldr r2, =0x7fff
    orr r1, r1, #0x4
    str r1, [r0, #0x1ac]
    mov r0, ip
    mov r1, #0x1f
    mov r3, #0x3f
    str ip, [sp, #0x0]
    bl G3X_SetClearColor
    mov r0, #0x0
    bl func_0200171c
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
