#include "m2c.h"

extern s32 data_021046fc;
extern void func_02065840(s32, s32);
extern s32 func_02066434(s32, s32, s32, s32);

// clang-format off
asm s32 func_020658e4(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r5, #0x0
    mov r9, r0
    mov r8, r1
    mov r7, r2
    mov r6, r5
    ldr r4, =data_021046fc
    b L_02065950
L_02065904:
    cmp r2, #0xa
    moveq r5, r8
    beq L_02065964
    cmp r2, #0x40
    bne L_02065930
    ldrb r1, [r8, #0x1]!
    mov r0, r9
    sub r1, r1, #0x31
    add r1, r4, r1, lsl #0x6
    bl func_02065840
    b L_02065948
L_02065930:
    ldr r1, [r9, #0x4]
    mov r0, r9
    cmp r2, #0x20
    cmpne r2, #0x2d
    moveq r5, r8
    bl func_02066434
L_02065948:
    add r6, r6, r0
    add r8, r8, #0x1
L_02065950:
    ldrb r2, [r8, #0x0]
    cmp r2, #0x0
    beq L_02065964
    cmp r6, r7
    ble L_02065904
L_02065964:
    cmp r2, #0x0
    bne L_02065974
    cmp r6, r7
    movle r5, r8
L_02065974:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
