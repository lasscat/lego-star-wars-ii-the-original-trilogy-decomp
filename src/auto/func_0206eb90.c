#include "m2c.h"

extern u32 data_021027f8[];

s32 func_0205d0d0(s32, s32, s32);

// clang-format off
asm void func_0206eb90(s32 *arg0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldr r0, =data_021027f8
    mov r1, #0x1
    mov r2, #0x4
    bl func_0205d0d0
    cmp r0, #0x0
    bne L_0206ebc8
    ldr r0, =data_021027f8
    mov r1, #0x2
    mov r2, #0x4
    bl func_0205d0d0
    cmp r0, #0x0
    ldmeqia sp!, {r4, pc}
L_0206ebc8:
    mov r1, #0x4
    mov r0, r4
    str r1, [r4, #0x68]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx r1
    ldmia sp!, {r4, pc}
}
// clang-format on
