#include "m2c.h"

s32 func_02067b54(s32);
void func_02067b48(s32, s32);
s32 func_020a97e0(s32, s32, s32);

// clang-format off
asm s32 func_020a9804(s32 *obj, s32 arg1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r5, r0
    ldr r0, [r5, #0x21c]
    mov r8, #0x0
    mov r4, r1
    mov r9, r8
    mov r10, r8
    bl func_02067b54
    cmp r0, #0x0
    bls L_020a9880
    mov r6, #0x1
L_020a9830:
    ldr r0, [r5, #0x21c]
    mov r1, r10
    bl func_02067b48
    mov r1, r0
    mov r0, r5
    mov r2, r4
    bl func_020a97e0
    cmp r9, #0x0
    beq L_020a985c
    cmp r0, r7
    bge L_020a9868
L_020a985c:
    mov r7, r0
    mov r9, r6
    mov r8, r10
L_020a9868:
    add r1, r10, #0x1
    ldr r0, [r5, #0x21c]
    and r10, r1, #0xff
    bl func_02067b54
    cmp r10, r0
    blo L_020a9830
L_020a9880:
    mov r0, r8
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
