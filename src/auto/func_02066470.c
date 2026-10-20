#include "m2c.h"

extern u32 data_021046fc[];

extern s32 func_02066708(s32 a0);
extern char *strchr(s32 a0, s32 a1);
extern s32 func_020e0db0(s32 a0);
extern void func_020de878(s32 a0, s32 a1, s32 a2);
extern void memcpy(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02066470(s32 a0, s32 a1) {
    stmfd sp!, {r4, r5, r6, r7, r8, lr}
    mov r0, r1
    mov r6, #0x0
    bl func_02066708
    mov r1, #0x40
    mov r7, r0
    bl strchr
    cmp r0, #0x0
    moveq r0, r7
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    ldrb r0, [r7, #0x0]
    cmp r0, #0x0
    beq L_02066530
    ldr r5, =data_021046fc
L_020664a8:
    ldrb r0, [r7, r6]
    add r1, r7, r6
    cmp r0, #0x40
    bne L_02066518
    ldrb r0, [r1, #0x1]
    sub r0, r0, #0x31
    add r8, r5, r0, lsl #0x6
    mov r0, r8
    bl func_020e0db0
    add r6, r6, #0x2
    mov r4, r0
    add r0, r7, r6
    bl func_020e0db0
    add r1, r6, r4
    mov r2, r0
    sub r0, r1, #0x2
    add r0, r7, r0
    add r2, r2, #0x1
    add r1, r7, r6
    bl func_020de878
    mov r1, r8
    sub r0, r6, #0x2
    add r0, r7, r0
    mov r2, r4
    bl memcpy
    sub r0, r4, #0x2
    add r6, r6, r0
    b L_02066524
L_02066518:
    cmp r0, #0xf0
    addhs r6, r6, #0x1
    add r6, r6, #0x1
L_02066524:
    ldrb r0, [r7, r6]
    cmp r0, #0x0
    bne L_020664a8
L_02066530:
    mov r0, r7
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
