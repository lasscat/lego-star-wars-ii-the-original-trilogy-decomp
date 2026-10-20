#include "m2c.h"

extern u32 data_0210930c[];
extern u32 data_021027f8[];

extern s32 func_0201eec4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0208c588(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208c4c8(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r7, #0x0
    ldr r5, =data_0210930c
    ldr r11, =data_021027f8
    mov r10, r0
    mov r9, r1
    mov r8, r7
    mov r4, #0xa
    mov r6, #0xe000
L_0208c4ec:
    add r1, r10, r8, lsl #0x2
    ldrb r0, [r1, #0xc]
    cmp r0, #0x0
    beq L_0208c56c
    cmp r8, #0x0
    bne L_0208c53c
    ldrb r0, [r1, #0xd]
    cmp r0, #0x0
    beq L_0208c53c
    ldrb r0, [r11, #0x2a]
    mov r1, r10
    mov r2, r6
    add r0, r5, r0, lsl #0x2
    ldr r0, [r0, #0x4c]
    str r6, [sp, #0x0]
    add r0, r0, #0xb0
    bl func_0201eec4
    cmp r0, #0x0
    addne r0, r10, r8, lsl #0x2
    strneb r4, [r0, #0xd]
L_0208c53c:
    add r1, r10, r8, lsl #0x2
    ldrb r0, [r1, #0xd]
    sub r0, r0, #0x1
    strb r0, [r1, #0xd]
    tst r0, #0xff
    bne L_0208c56c
    mov r0, r10
    cmp r8, #0x0
    mov r1, r8
    mov r2, r9
    moveq r7, #0x1
    bl func_0208c588
L_0208c56c:
    add r8, r8, #0x1
    cmp r8, #0x2
    blo L_0208c4ec
    mov r0, r7
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
