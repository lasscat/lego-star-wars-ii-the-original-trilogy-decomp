#include "m2c.h"

extern M2C_UNK data_0210930c[];

void func_02017e8c(s32, s32);
void func_01ffa338(s32, s32, s32, s32, s32, s32);

// clang-format off
asm void func_0203fe38(s32 *out, s32 a1, s32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x20
    mov r6, r0
    mov r3, #0x0
    str r3, [r6, #0x0]
    str r3, [r6, #0x4]
    str r3, [r6, #0x8]
    str r3, [r6, #0xc]
    mov r0, #0x2000
    str r0, [r6, #0x10]
    movs r5, r1
    str r3, [r6, #0x14]
    mov r4, r2
    addeq sp, sp, #0x20
    str r3, [r6, #0x18]
    ldmeqia sp!, {r4, r5, r6, pc}
    add r2, sp, #0x8
    mov r1, r3
    add r0, sp, #0x20
L_0203fe84:
    str r1, [r2], #0x4
    cmp r2, r0
    blo L_0203fe84
    add r1, sp, #0x8
    mov r0, r5
    bl func_02017e8c
    ldr r0, =data_0210930c
    add r2, sp, #0x8
    ldr r1, [r0, #0x68]
    mov r0, r5
    ldr r1, [r1, #0x384]
    mov r3, r4
    stmia sp, {r1, r6}
    ldr r1, [r5, #0x20]
    bl func_01ffa338
    add sp, sp, #0x20
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
