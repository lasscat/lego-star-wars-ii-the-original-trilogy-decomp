#include "m2c.h"

void func_020d2898(s32);
s32 FS_OpenFile(s32, s32);
void func_020d2bc0(s32);
s32 func_020d2cbc(s32, s32, s32);

// clang-format off
asm void MBi_ReadIconInfo(s32 *a0, s32 *a1, s32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x48
    cmp r2, #0x0
    movne r4, #0x200
    moveq r4, #0x20
    mov r6, r0
    mov r5, r1
    cmp r2, #0x0
    addne r5, r5, #0x20
    cmp r6, #0x0
    addeq sp, sp, #0x48
    moveq r0, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
    add r0, sp, #0x0
    bl func_020d2898
    add r0, sp, #0x0
    mov r1, r6
    bl FS_OpenFile
    cmp r0, #0x0
    addeq sp, sp, #0x48
    moveq r0, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
    ldr r1, [sp, #0x28]
    ldr r0, [sp, #0x24]
    sub r0, r1, r0
    cmp r4, r0
    add r0, sp, #0x0
    beq L_020dabdc
    bl func_020d2bc0
    add sp, sp, #0x48
    mov r0, #0x0
    ldmia sp!, {r4, r5, r6, pc}
L_020dabdc:
    mov r1, r5
    mov r2, r4
    bl func_020d2cbc
    add r0, sp, #0x0
    bl func_020d2bc0
    mov r0, #0x1
    add sp, sp, #0x48
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
