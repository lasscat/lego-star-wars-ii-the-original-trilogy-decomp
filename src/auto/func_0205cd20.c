#include "m2c.h"

extern u32 data_020fe5c8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205cd20(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr     r3, =data_020fe5c8
    mov ip, #0x0
    ldr r6, [r3, #0x4]
    mov lr, ip
    cmp r6, #0x0
    moveq r0, #0x1
    ldmeqia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r3, [r3, #0x0]
    mov r5, ip
    ldr r4, [r3, r0, lsl #0x2]
    mov r0, ip
    ldrb r3, [r6, r4]
    add r4, r6, r4
    add r4, r4, #0x1
    L_0205cd5c:
    ldr     r6, =data_020fe5c8
    mov r9, #0x100
    ldr r6, [r6, #0x8]
    mov r8, #0x0
    L_0205cd6c:
    mov r7, r3, asr r0
    tst r7, #0x1
    add r7, r6, r9, lsl #0x2
    subne r7, r7, #0x300
    ldrneh r9, [r7, #-0xfe]
    subeq r7, r7, #0x400
    add r0, r0, #0x1
    ldreqh r9, [r7, #0x0]
    cmp r0, #0x8
    ldreqb r3, [r4], #0x1
    moveq r0, r8
    cmp r9, #0x100
    bhs      L_0205cd6c
    and r6, r9, #0xff
    strb r6, [r1, r5]
    cmp r6, #0xf0
    add r5, r5, #0x1
    blo      L_0205cdcc
    cmp lr, #0x0
    bne      L_0205cdcc
    mov r6, r6, lsl #0x18
    mov ip, r6, lsr #0x10
    mov lr, #0x1
    b      L_0205cdec
    L_0205cdcc:
    cmp lr, #0x0
    beq      L_0205cde4
    and r6, r9, #0xff
    orr ip, ip, r6
    mov lr, #0x0
    b      L_0205cdec
    L_0205cde4:
    andeq r6, r9, #0xff
    orreq ip, r6, #0x0
    L_0205cdec:
    add r6, r1, r5
    ldrb r6, [r6, #-0x1]
    cmp r6, #0x0
    beq      L_0205ce08
    cmp r5, r2
    moveq r0, #0x2
    ldmeqia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    L_0205ce08:
    cmp ip, #0x0
    bne      L_0205cd5c
    mov r0, #0x0
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
