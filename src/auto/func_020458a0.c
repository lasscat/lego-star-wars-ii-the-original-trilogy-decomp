#include "m2c.h"

extern u32 data_020f6bab[];
extern void func_0204a1c4();
extern void func_02045990();
extern void func_02045cf0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020458a0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r0, [r5, #0x4]
    mov r1, #0x0
    ldrb r3, [r0, #0x6c3]
    mov r0, #0x24
    ldr     r2, =data_020f6bab
    strb r1, [r5, #0xd]
    ldr r1, [r5, #0x4]
    smulbb r3, r3, r0
    ldr r0, [r1, #0x8]
    ldrb r4, [r2, r3]
    orr r0, r0, #0x200
    str r0, [r1, #0x8]
    ldr r0, [r5, #0x4]
    add r0, r0, #0xce
    add r0, r0, #0x500
    bl      func_0204a1c4
    ldr r1, [r5, #0x14]
    mov r2, #0x0
    cmp r1, #0x0
    beq      L_02045920
    ldr r3, [r1, #0x0]
    add r0, r5, #0x14
    cmp r3, r0
    beq      L_02045918
    L_02045908:
    add r1, r3, #0x4
    ldr r3, [r3, #0x4]
    cmp r3, r0
    bne      L_02045908
    L_02045918:
    ldr r0, [r5, #0x18]
    str r0, [r1, #0x0]
    L_02045920:
    cmp r2, #0x0
    moveq r0, #0x0
    streq r0, [r5, #0x14]
    streq r0, [r5, #0x18]
    beq      L_02045948
    str r2, [r5, #0x14]
    ldr r1, [r2, #0x0]
    add r0, r5, #0x14
    str r1, [r5, #0x18]
    str r0, [r2, #0x0]
    L_02045948:
    cmp r4, #0x3
    addls pc, pc, r4, lsl #0x2
    b      L_0204597c
    L_02045954:
    b      L_02045964
    b      L_02045970
    b      L_02045964
    b      L_02045964
    L_02045964:
    mov r0, r5
    bl      func_02045990
    ldmia   sp!, {r3, r4, r5, pc}
    L_02045970:
    mov r0, r5
    bl      func_02045cf0
    ldmia   sp!, {r3, r4, r5, pc}
    L_0204597c:
    ldrb r0, [r5, #0xc]
    orr r0, r0, #0x1
    strb r0, [r5, #0xc]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
