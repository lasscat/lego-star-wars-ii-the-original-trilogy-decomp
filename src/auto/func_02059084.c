#include "m2c.h"

extern M2C_UNK data_020ee898[];

s32 func_02067080(s32, s32, s32);
void func_0202c498(s32, s32);

// clang-format off
asm void func_02059084(s32 *obj, s32 *arg) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r6, r1
    ldrb r2, [r6, #0x0]
    mov r7, r0
    ldr r0, [r7, #0x4]
    cmp r2, #0x0
    moveq r5, #0x0
    beq L_020590b4
    ldr r1, [r0, #0x2c]
    sub r0, r2, #0x1
    add r0, r1, r0, lsl #0x3
    ldrb r5, [r0, #0x5]
L_020590b4:
    mov r4, #0x1
    cmp r5, #0x1
    ldmloia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r8, =data_020ee898
    sub r9, r2, #0x1
L_020590c8:
    mov r0, r7
    mov r1, r9
    mov r2, r4
    bl func_02067080
    cmp r0, #0x0
    beq L_020590f8
    ldrb r1, [r6, #0x1]
    cmp r1, #0xc
    ldreqb r1, [r0, #0x6bb]
    add r0, r0, #0x5e0
    ldreqb r1, [r8, r1, lsl #0x2]
    bl func_0202c498
L_020590f8:
    add r4, r4, #0x1
    cmp r4, r5
    bls L_020590c8
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
