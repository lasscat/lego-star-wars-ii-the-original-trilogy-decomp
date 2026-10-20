#include "m2c.h"

extern s32 NNS_G3dFuncAnmJntNsBcaDefault;
extern void MIi_CpuClear16(u16, void *);

// clang-format off
asm void NNSi_G3dAnmObjInitNsBca(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    ldr r0, =NNS_G3dFuncAnmJntNsBcaDefault
    str r4, [r5, #0x8]
    ldr r0, [r0, #0x0]
    add r1, r5, #0x1a
    str r0, [r5, #0xc]
    ldrb r2, [r2, #0x17]
    mov r0, #0x0
    strb r2, [r5, #0x19]
    mov r2, r2, lsl #0x1
    bl MIi_CpuClear16
    ldrh r0, [r4, #0x6]
    add r3, r4, #0x14
    mov r2, #0x0
    cmp r0, #0x0
    ldmlsia sp!, {r3, r4, r5, pc}
L_020c66f8:
    mov r0, r2, lsl #0x1
    ldrh r1, [r3, r0]
    add r0, r5, r2, lsl #0x1
    add r2, r2, #0x1
    ldr r1, [r4, r1]
    mov r1, r1, lsr #0x18
    orr r1, r1, #0x100
    strh r1, [r0, #0x1a]
    ldrh r0, [r4, #0x6]
    cmp r2, r0
    blo L_020c66f8
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
