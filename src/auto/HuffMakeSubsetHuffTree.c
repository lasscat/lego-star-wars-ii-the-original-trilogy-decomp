#include "m2c.h"

extern u32 HuffTreeTop[];

void HuffSetOneNodeOffset(s32, s32);

// clang-format off
asm void HuffMakeSubsetHuffTree(s32 arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    ldr r2, =HuffTreeTop
    mov r5, r1
    mov r4, r0
    ldrb r9, [r2, #0x0]
    bl HuffSetOneNodeOffset
    cmp r5, #0x0
    mov r0, #0x6
    mov r2, #0x0
    beq L_020d0158
    ldr r1, =HuffTreeTop
    ldr r1, [r1, #0x8]
    mla r0, r4, r0, r1
    strb r2, [r0, #0x1]
    b L_020d0168
L_020d0158:
    mul r1, r4, r0
    ldr r0, =HuffTreeTop
    ldr r0, [r0, #0x8]
    strb r2, [r0, r1]
L_020d0168:
    ldr r5, =HuffTreeTop
    ldrb r0, [r5, #0x0]
    cmp r9, r0
    ldmhsia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r8, #0x0
    mov r7, r8
    mov r11, #0x1
    mov r6, r8
    mov r4, #0x6
L_020d018c:
    mul r10, r9, r4
    ldr r0, [r5, #0x8]
    ldrb r0, [r0, r10]
    cmp r0, #0x0
    beq L_020d01b4
    mov r0, r9
    mov r1, r8
    bl HuffSetOneNodeOffset
    ldr r0, [r5, #0x8]
    strb r7, [r0, r10]
L_020d01b4:
    ldr r0, [r5, #0x8]
    add r0, r0, r10
    ldrb r0, [r0, #0x1]
    cmp r0, #0x0
    beq L_020d01e0
    mov r0, r9
    mov r1, r11
    bl HuffSetOneNodeOffset
    ldr r0, [r5, #0x8]
    add r0, r0, r10
    strb r6, [r0, #0x1]
L_020d01e0:
    ldrb r0, [r5, #0x0]
    add r1, r9, #0x1
    and r9, r1, #0xff
    cmp r9, r0
    blo L_020d018c
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
