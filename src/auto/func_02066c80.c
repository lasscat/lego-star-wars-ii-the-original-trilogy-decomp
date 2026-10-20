#include "m2c.h"

extern u8 data_020fe720[];
extern u8 data_02104914[];

extern s32 sprintf(s32, s32);
extern s32 func_020c93c8(s32);

// clang-format off
asm s32 func_02066c80(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x20
    mov r2, r1
    add r5, sp, #0x0
    mov r6, r0
    ldr r1, =data_020fe720
    mov r0, r5
    bl sprintf
    mov r1, #0x3
    mov r4, r0
    bl func_020c93c8
    cmp r0, #0x0
    moveq r0, #0x3
    cmp r0, #0x0
    sub r0, r0, #0x1
    beq L_02066cd8
L_02066cc0:
    ldrsb r1, [r5], #0x1
    cmp r0, #0x0
    sub r4, r4, #0x1
    strb r1, [r6], #0x1
    sub r0, r0, #0x1
    bne L_02066cc0
L_02066cd8:
    cmp r4, #0x0
    beq L_02066d18
    ldr r0, =data_02104914
L_02066ce4:
    ldrb r2, [r0, #0x1]
    add r1, r5, #0x2
    subs r4, r4, #0x3
    strb r2, [r6, #0x0]
    ldrsb r2, [r5, #0x0]
    strb r2, [r6, #0x1]
    ldrsb r2, [r5, #0x1]
    add r5, r5, #0x3
    strb r2, [r6, #0x2]
    ldrsb r1, [r1, #0x0]
    strb r1, [r6, #0x3]
    add r6, r6, #0x4
    bne L_02066ce4
L_02066d18:
    mov r0, #0x0
    strb r0, [r6, #0x0]
    add sp, sp, #0x20
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
