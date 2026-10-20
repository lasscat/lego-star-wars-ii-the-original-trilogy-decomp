#include "m2c.h"

extern u32 data_02103374[];
extern u32 data_020edc50[];
extern u32 data_02103a95[];

void func_0205e724(s32, s32, s32, s32, s32);

// clang-format off
asm void func_02060b44(s32 arg0) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    ldr r1, =0x724
    ldr r3, =data_02103374
    mul r4, r0, r1
    ldr r1, =data_020edc50
    add lr, r3, r4
    ldr ip, [r1, #0x0]
    ldr r2, [r1, #0x4]
    str ip, [sp, #0x8]
    str r2, [sp, #0x4]
    mov r3, #0x0
L_02060b74:
    str ip, [lr, r3, lsl #0x3]
    add r1, lr, r3, lsl #0x3
    add r3, r3, #0x1
    str r2, [r1, #0x4]
    cmp r3, #0x80
    blt L_02060b74
    ldr r1, =data_02103374
    mov r0, r0, lsl #0xa
    mov ip, #0x20
    add r1, r1, r4
    add r2, r0, #0x7000000
    mov r0, #0x3
    mov r3, #0x400
    str ip, [sp, #0x0]
    bl func_0205e724
    ldr r0, =data_02103a95
    mov r1, #0x0
    strb r1, [r0, r4]
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
