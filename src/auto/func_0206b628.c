#include "m2c.h"

extern u8 data_02104364[];
extern void func_020b8f70(s32, s32);
extern void func_020b8f48(void);
extern void func_020b8f20(void);

// clang-format off
asm s32 func_0206b628(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    ldr r0, =data_02104364
    ldr r3, [r7, #0x18]
    ldrb r5, [r0, #0xa]
    cmp r3, #0x1
    mov r6, r2
    ldreqb r5, [r0, #0x9]
    mov r4, #0x0
    cmp r1, #0x0
    beq L_0206b67c
    cmp r5, #0x0
    beq L_0206b6a0
    mov r0, #0xb6
    mov r1, #0x0
    bl func_020b8f70
    cmp r6, #0x0
    subeq r5, r5, #0x1
    movne r5, #0x0
    mov r4, #0x1
    b L_0206b6a0
L_0206b67c:
    cmp r5, #0x7f
    bge L_0206b6a0
    mov r0, #0xb6
    mov r1, #0x0
    bl func_020b8f70
    cmp r6, #0x0
    addeq r5, r5, #0x1
    movne r5, #0x7f
    mov r4, #0x1
L_0206b6a0:
    ldr r0, [r7, #0x18]
    cmp r0, #0x0
    bne L_0206b6cc
    ldr r1, =data_02104364
    and r0, r5, #0xff
    ldrb r2, [r1, #0xa]
    cmp r2, r0
    beq L_0206b6e8
    strb r0, [r1, #0xa]
    bl func_020b8f48
    b L_0206b6e8
L_0206b6cc:
    ldr r1, =data_02104364
    and r0, r5, #0xff
    ldrb r2, [r1, #0x9]
    cmp r2, r0
    beq L_0206b6e8
    strb r0, [r1, #0x9]
    bl func_020b8f20
L_0206b6e8:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
