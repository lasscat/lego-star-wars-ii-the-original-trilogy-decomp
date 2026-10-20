#include "m2c.h"

extern u32 mbc[];

s32 _u32_div_f(s32, s32);
s32 func_020da91c(s32, s32, s32);

// clang-format off
asm s32 MBi_MakeBlockInfoTable(s32 *arg0, s32 *arg1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r10, r0
    add r6, r10, #0xc
    cmp r1, #0x0
    mov r0, #0x0
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
    mov r2, r0
L_020da70c:
    str r0, [r10, r2, lsl #0x2]
    add r3, r1, r2, lsl #0x4
    add r2, r2, #0x1
    ldr r3, [r3, #0x14]
    and r2, r2, #0xff
    cmp r2, #0x3
    add r0, r0, r3
    blo L_020da70c
    mov r9, #0x0
    ldr r4, =mbc
    strh r9, [r6, #0x0]
    add r5, r1, #0xc
L_020da73c:
    ldr r0, [r4, #0x0]
    add r7, r5, r9, lsl #0x4
    add r0, r0, #0x1000
    ldr r1, [r0, #0x318]
    ldr r8, [r7, #0x8]
    add r0, r8, r1
    sub r0, r0, #0x1
    bl _u32_div_f
    mov r1, r9, lsl #0x1
    ldrh r3, [r6, r1]
    mov r2, r0, lsl #0x10
    ldr r1, [r7, #0x4]
    add r2, r3, r2, lsr #0x10
    mov r3, r2, lsl #0x10
    mov r0, r9
    mov r2, r8
    mov r7, r3, lsr #0x10
    bl func_020da91c
    cmp r0, #0x0
    moveq r0, #0x0
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
    cmp r9, #0x2
    addlo r0, r6, r9, lsl #0x1
    strloh r7, [r0, #0x2]
    add r0, r9, #0x1
    and r9, r0, #0xff
    strhsh r7, [r10, #0x12]
    cmp r9, #0x3
    blo L_020da73c
    mov r0, #0x1
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
