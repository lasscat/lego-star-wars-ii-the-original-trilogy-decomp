#include "m2c.h"

extern u32 data_020ff9b4[];

extern void func_0200c834(s32, s32);

// clang-format off
asm void func_0203835c(s32 a0) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r0, [r4, #0x4]
    mov r1, #0x4
    bl func_0200c834
    ldr r0, [r4, #0x4]
    mov r1, #0x5
    bl func_0200c834
    ldr r0, [r4, #0x4]
    ldr r1, =0x20d
    ldr r3, [r0, #0x0]
    mov r2, #0x1
    ldr r3, [r3, #0x30]
    blx r3
    ldr r0, [r4, #0x4]
    mov r1, #0x1
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x34]
    blx r2
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r1, #0x47
    mov r3, #0x1
    ldr ip, [r0, #0x0]
    ldr ip, [ip, #0x24]
    blx ip
    ldr r0, [r4, #0x4]
    ldr r1, =data_020ff9b4
    add r2, r0, #0x60
    cmp r2, r1
    beq L_020383f8
    ldr r0, [r1, #0x0]
    str r0, [r2, #0x0]
    ldr r0, [r1, #0x4]
    str r0, [r2, #0x4]
    ldr r0, [r1, #0x8]
    str r0, [r2, #0x8]
L_020383f8:
    ldr r3, [r4, #0x4]
    mov r2, #0x1d
    ldr r1, [r3, #0x8]
    mov r0, #0x1
    orr r1, r1, #0x800
    str r1, [r3, #0x8]
    ldr r1, [r4, #0x4]
    str r2, [r1, #0x84]
    strb r0, [r4, #0xd]
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
