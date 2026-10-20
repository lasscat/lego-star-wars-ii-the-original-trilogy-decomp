#include "m2c.h"

extern u32 current_dir_pos[];
extern void FS_FindArchive();
extern void FSi_SendCommand();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_FindPath(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #12
    mov r7, r1
    ldrb r1, [r7]
    mov r8, r0
    mov r6, r2
    cmp r1, #47
    mov r5, r3
    cmpne r1, #92
    bne    L_020d290c
    ldr     r0, =current_dir_pos
    mov r1, #0
    ldr r0, [r0]
    strh r1, [sp, #4]
    str r0, [sp]
    str r1, [sp, #8]
    strh r1, [sp, #6]
    add r7, r7, #1
    b      L_020d29b0
L_020d290c:
    ldr     r0, =current_dir_pos
    add r3, sp, #0
    ldmia r0, {r0, r1, r2}
    stmia r3, {r0, r1, r2}
    mov r4, #0
L_020d2920:
    ldrb r0, [r7, r4]
    cmp r0, #0
    cmpne r0, #47
    cmpne r0, #92
    beq    L_020d29b0
    cmp r0, #58
    bne    L_020d29a4
    mov r0, r7
    mov r1, r4
    bl     FS_FindArchive
    cmp r0, #0
    addeq sp, sp, #12
    moveq r0, #0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, pc}
    ldr r1, [r0, #0x1c]
    tst r1, #2
    movne r1, #1
    moveq r1, #0
    cmp r1, #0
    addeq sp, sp, #12
    moveq r0, #0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, pc}
    mov r1, #0
    str r0, [sp]
    str r1, [sp, #8]
    strh r1, [sp, #6]
    strh r1, [sp, #4]
    add r0, r4, #1
    ldrb r0, [r7, r0]!
    cmp r0, #47
    cmpne r0, #92
    addeq r7, r7, #1
    b      L_020d29b0
L_020d29a4:
    add r4, r4, #1
    cmp r4, #3
    ble    L_020d2920
L_020d29b0:
    ldr r1, [sp]
    add r0, sp, #0
    str r1, [r8, #8]
    str r7, [r8, #0x3c]
    add r3, r8, #48
    ldmia r0, {r0, r1, r2}
    stmia r3, {r0, r1, r2}
    cmp r5, #0
    moveq r0, #0
    streq r0, [r8, #0x40]
    streq r6, [r8, #0x44]
    beq    L_020d29ec
    mov r0, #1
    str r0, [r8, #0x40]
    str r5, [r8, #0x44]
L_020d29ec:
    mov r0, r8
    mov r1, #4
    bl     FSi_SendCommand
    add sp, sp, #12
    ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
}
// clang-format on
