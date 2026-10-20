#include "m2c.h"

extern u32 data_021027f8[];
extern u32 data_02104d90[];
extern u32 data_02102900[];

s32 func_0207a8c4(s32);
s32 func_0205d0d0(s32, s32, s32);
void func_02087044(s32);
void func_0205ecc4(s32, s32, s32, s32);
void func_020b8f70(s32, s32);
s32 func_020780a4(s32);
s32 func_020782a8(s32);
s32 func_020784b8(s32);
void func_02077170(s32);

// clang-format off
asm void func_02077088(s32 *arg0) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    bl func_0207a8c4
    cmp r0, #0x0
    addne sp, sp, #0x8
    ldmneia sp!, {r4, pc}
    ldr r0, =data_021027f8
    mov r1, #0x2
    mov r2, #0x4
    bl func_0205d0d0
    cmp r0, #0x0
    beq L_020770f4
    ldr r0, =data_02104d90
    bl func_02087044
    mov r2, #0x1
    ldr r0, =data_02102900
    str r2, [sp, #0x0]
    mov r3, #0x0
    mov r1, #0x30
    str r3, [sp, #0x4]
    bl func_0205ecc4
    mov r0, #0xb5
    mov r1, #0x0
    bl func_020b8f70
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
L_020770f4:
    mov r0, r4
    bl func_020780a4
    cmp r0, #0x0
    addne sp, sp, #0x8
    ldmneia sp!, {r4, pc}
    ldrb r0, [r4, #0xd0]
    cmp r0, #0x3
    bhs L_02077128
    mov r0, r4
    bl func_020782a8
    cmp r0, #0x0
    addne sp, sp, #0x8
    ldmneia sp!, {r4, pc}
L_02077128:
    ldrb r0, [r4, #0xd0]
    cmp r0, #0x3
    bne L_02077148
    mov r0, r4
    bl func_020784b8
    cmp r0, #0x0
    addne sp, sp, #0x8
    ldmneia sp!, {r4, pc}
L_02077148:
    mov r0, r4
    bl func_02077170
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
}
// clang-format on
