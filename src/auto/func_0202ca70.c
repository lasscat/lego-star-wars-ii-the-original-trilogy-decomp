#include "m2c.h"

extern void func_01ff90a8(s32);

// clang-format off
asm void func_0202ca70(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r10, r0
    ldr r0, [r10, #0x18]
    mov r9, r1
    mov r8, r2
    mov r6, r3
    cmp r0, #0x0
    beq L_0202cab8
    ldr r3, [r0, #0x0]
    ldr r3, [r3, #0x18]
    blx r3
    cmp r0, #0x1
    bne L_0202cab8
    mov r0, r10
    bl func_01ff90a8
    tst r6, #0x1
    moveq r0, #0x1
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
L_0202cab8:
    ldr r5, [r10, #0x4]
    mov r4, #0x0
    cmp r5, #0x0
    subne r5, r5, #0x4
    cmp r5, #0x0
    beq L_0202cb3c
    and r7, r6, #0x1
    mov r11, r4
L_0202cad8:
    mov r0, r10
    ldr r3, [r0, #0x0]
    mov r1, r5
    ldr r3, [r3, #0x1c]
    cmp r5, #0x0
    addne r1, r5, #0x4
    mov r2, r11
    blx r3
    movs r6, r0
    ldr r0, [r5, #0x4]
    mov r1, r9
    ldr r3, [r0, #0x0]
    mov r2, r8
    ldr r3, [r3, #0x18]
    subne r6, r6, #0x4
    blx r3
    cmp r0, #0x1
    bne L_0202cb30
    cmp r7, #0x0
    moveq r0, #0x1
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r4, #0x1
L_0202cb30:
    mov r5, r6
    cmp r6, #0x0
    bne L_0202cad8
L_0202cb3c:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
