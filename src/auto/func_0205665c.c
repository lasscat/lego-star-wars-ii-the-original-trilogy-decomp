#include "m2c.h"

extern u32 data_0210930c[];

extern void func_020922f4(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205665c(s32 a0, s32 a1) {
    stmfd sp!, {r3, lr}
    ldr ip, =data_0210930c
    mvn r3, #0x0
    mov lr, #0x0
L_0205666c:
    add r0, ip, lr, lsl #0x2
    ldr r0, [r0, #0x4c]
    cmp r0, #0x0
    beq L_020566a0
    ldrb r2, [r1, #0x0]
    ldrb r0, [r0, #0x6bb]
    cmp r2, r0
    add r0, lr, #0x1
    mov r0, r0, lsl #0x18
    moveq r3, lr
    mov lr, r0, asr #0x18
    cmp lr, #0x4
    blt L_0205666c
L_020566a0:
    sub r0, lr, #0x1
    mov r0, r0, lsl #0x18
    mov r2, r0, asr #0x18
    cmp r2, r3
    mvnne r0, #0x0
    cmpne r3, r0
    ldmeqia sp!, {r3, pc}
    ldr r0, =data_0210930c
    mov r1, r3
    bl func_020922f4
    ldmia sp!, {r3, pc}
}
// clang-format on
