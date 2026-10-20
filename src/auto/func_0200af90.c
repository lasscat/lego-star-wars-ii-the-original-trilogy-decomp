#include "m2c.h"

extern u32 data_020e5cc0[];
extern void func_0200fe94();
extern u32 data_020fcd30[];
extern u32 data_020e5cc2[];
extern void func_020b95bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200af90(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #16
    mov r5, r2
    ldr     r2, =data_020e5cc0
    mov r6, r5, lsl #2
    ldrh r2, [r2, r6]
    mov r4, r3
    ldr ip, [sp, #0x24]
    ldr r3, [sp, #0x20]
    mov r6, r0
    str ip, [sp]
    bl     func_0200fe94
    ldr     r0, =data_020fcd30
    mov r2, #0
    str r0, [r6]
    strb r2, [r6, #0x1be]
    strb r5, [r6, #0x1bf]
    mov r1, r4, lsl #12
    str r1, [sp, #4]
    str r1, [sp, #8]
    str r1, [sp, #0xc]
    ldr r0, [r6, #0xbc]
    add r3, sp, #4
    cmp r0, r4, lsl #12
    ldreq r0, [r6, #0xc0]
    cmpeq r0, r1
    ldreq r0, [r6, #0xc4]
    cmpeq r0, r1
    movne r2, #1
    cmp r2, #0
    beq    L_0200b038
    add r0, r6, #188
    cmp r0, r3
    beq    L_0200b030
    ldr r0, [r3]
    str r0, [r6, #0xbc]
    ldr r0, [r3, #4]
    str r0, [r6, #0xc0]
    ldr r0, [r3, #8]
    str r0, [r6, #0xc4]
L_0200b030:
    mov r0, #1
    strb r0, [r6, #0xd1]
L_0200b038:
    mov r1, #0
    mov r0, r6
    str r1, [sp]
    ldr r4, [r0]
    mov r2, r1
    ldr r4, [r4, #0x24]
    mov r3, r1
    blx r4
    cmp r5, #7
    bne    L_0200b080
    mov r2, #0
    mov r0, r6
    str r2, [sp]
    ldr r4, [r0]
    mov r3, r2
    ldr r4, [r4, #0x24]
    mov r1, #138
    blx r4
L_0200b080:
    ldr r0, [r6, #0x148]
    cmp r0, #0
    moveq r2, #0
    beq    L_0200b09c
    ldr r0, [r0, #8]
    ldrh r0, [r0, #4]
    mov r2, r0, lsl #12
L_0200b09c:
    ldr     r0, =data_020e5cc2
    mov r1, r5, lsl #2
    ldrh r0, [r0, r1]
    mov r2, r2, asr #12
    add r1, r6, #256
    strh r2, [r1, #0xbc]
    cmp r0, #201
    beq    L_0200b0c4
    mov r1, r6
    bl     func_020b95bc
L_0200b0c4:
    mov r0, r6
    add sp, sp, #16
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
