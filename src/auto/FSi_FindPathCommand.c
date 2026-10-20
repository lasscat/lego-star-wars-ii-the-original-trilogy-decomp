#include "m2c.h"

extern void FSi_TranslateCommand();
extern void FSi_SeekDirDirect();
extern void FSi_StrNICmp();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_FindPathCommand(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #148
    mov r9, r0
    ldr r5, [sb, #0x3c]
    mov r1, #2
    ldr r6, [sb, #0x40]
    bl     FSi_TranslateCommand
    ldrb r3, [r5]
    cmp r3, #0
    beq    L_020d1b54
L_020d19c4:
    mov r8, #0
    mov r0, #1
    mov r1, r8
    b      L_020d19d8
L_020d19d4:
    add r8, r8, #1
L_020d19d8:
    ldrb r7, [r5, r8]
    mov r2, r1
    cmp r7, #0
    cmpne r7, #47
    cmpne r7, #92
    movne r2, r0
    cmp r2, #0
    bne    L_020d19d4
    cmp r7, #0
    cmpeq r6, #0
    movne r7, #1
    cmp r8, #0
    addeq sp, sp, #148
    moveq r0, #1
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    cmp r3, #46
    bne    L_020d1a6c
    cmp r8, #1
    addeq r5, r5, #1
    beq    L_020d1b38
    ldrb r0, [r5, #1]
    cmp r8, #2
    moveq r1, #1
    movne r1, #0
    cmp r0, #46
    moveq r0, #1
    movne r0, #0
    tst r1, r0
    beq    L_020d1a6c
    ldrh r0, [sb, #0x24]
    cmp r0, #0
    beq    L_020d1a64
    ldr r1, [sb, #0x2c]
    mov r0, r9
    bl     FSi_SeekDirDirect
L_020d1a64:
    add r5, r5, #2
    b      L_020d1b38
L_020d1a6c:
    cmp r8, #127
    addgt sp, sp, #148
    movgt r0, #1
    ldmgtia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    add r1, sp, #0
    mov r0, #0
    str r1, [sb, #0x30]
    str r0, [sb, #0x34]
    add r10, sp, #20
    mov r4, #3
L_020d1a94:
    mov r0, r9
    mov r1, r4
    bl     FSi_TranslateCommand
    cmp r0, #0
    addne sp, sp, #148
    movne r0, #1
    ldmneia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r0, [sp, #0xc]
    cmp r7, r0
    ldreq r0, [sp, #0x10]
    cmpeq r8, r0
    bne    L_020d1a94
    mov r0, r5
    mov r1, r10
    mov r2, r8
    bl     FSi_StrNICmp
    cmp r0, #0
    bne    L_020d1a94
    cmp r7, #0
    beq    L_020d1b08
    add r0, sp, #0
    add r3, r9, #48
    ldmia r0, {r0, r1, r2}
    stmia r3, {r0, r1, r2}
    mov r0, r9
    mov r1, #2
    add r5, r5, r8
    bl     FSi_TranslateCommand
    b      L_020d1b38
L_020d1b08:
    cmp r6, #0
    addne sp, sp, #148
    movne r0, #1
    ldmneia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r3, [sb, #0x44]
    ldr r2, [sp]
    ldr r1, [sp, #4]
    add sp, sp, #148
    str r2, [r3]
    mov r0, #0
    str r1, [r3, #4]
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
L_020d1b38:
    ldrb r0, [r5]
    cmp r0, #0
    movne r0, #1
    moveq r0, #0
    ldrb r3, [r5, r0]!
    cmp r3, #0
    bne    L_020d19c4
L_020d1b54:
    cmp r6, #0
    addeq sp, sp, #148
    moveq r0, #1
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r3, [sb, #0x44]
    add r0, r9, #32
    ldmia r0, {r0, r1, r2}
    stmia r3, {r0, r1, r2}
    mov r0, #0
    add sp, sp, #148
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
