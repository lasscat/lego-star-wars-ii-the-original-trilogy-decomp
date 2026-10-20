#include "m2c.h"

extern M2C_UNK data_020eebb8[];
extern M2C_UNK data_020ef581[];

void func_020063d4(s32, s32);
void func_02004404(s32);

// clang-format off
asm void func_02006220(s32 *obj, s32 arg1) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r8, r0
    ldrb r0, [r8, #0x6bb]
    mov r6, #0x0
    ldr r2, =data_020eebb8
    add r0, r0, r0, lsl #0x2
    mov r7, r1
    add r5, r2, r0
    mov r9, r6
    mov r4, #0xfa
L_02006248:
    ldrb r1, [r5, r6]
    cmp r1, #0xfa
    beq L_02006264
    mov r0, r8
    mov r2, r7
    bl func_020063d4
    b L_0200627c
L_02006264:
    add r0, r8, r6, lsl #0x1
    add r0, r0, #0x600
    strh r4, [r0, #0xe8]
    cmp r6, #0x4
    streqb r9, [r8, #0x1df]
    streqb r9, [r8, #0x207]
L_0200627c:
    add r6, r6, #0x1
    cmp r6, #0x5
    blo L_02006248
    ldrb r2, [r8, #0x6bb]
    mov r0, #0x18
    ldr r1, =data_020ef581
    smulbb r0, r2, r0
    ldrb r1, [r1, r0]
    mov r0, r8
    strb r1, [r8, #0x6c3]
    bl func_02004404
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
