#include "m2c.h"

extern s32 AllocUsedBlockFromFreeBlock(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void AllocFromTail(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldrh r4, [r0, #0x36]
    mov r3, r1
    ldr ip, [r0, #0x28]
    and r1, r4, #0x1
    mov r1, r1, lsl #0x10
    movs r1, r1, lsr #0x10
    mov r1, #0x0
    moveq r5, #0x1
    movne r5, #0x0
    mov r4, r1
    cmp ip, #0x0
    sub lr, r1, #0x1
    beq L_020c25ec
    sub r2, r2, #0x1
    mvn r2, r2
L_020c25a0:
    ldr r8, [ip, #0x4]
    add r9, ip, #0x10
    add r6, r8, r9
    sub r6, r6, r3
    and r7, r2, r6
    subs r6, r7, r9
    bmi L_020c25e0
    cmp lr, r8
    bls L_020c25e0
    mov r1, ip
    mov lr, r8
    mov r4, r7
    cmp r5, #0x0
    bne L_020c25ec
    cmp r8, r3
    beq L_020c25ec
L_020c25e0:
    ldr ip, [ip, #0x8]
    cmp ip, #0x0
    bne L_020c25a0
L_020c25ec:
    cmp r1, #0x0
    moveq r0, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r5, #0x1
    mov r2, r4
    add r0, r0, #0x24
    str r5, [sp, #0x0]
    bl AllocUsedBlockFromFreeBlock
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
