#include "m2c.h"

extern u32 data_020fcd18[];
extern void func_0200af88();
extern u32 data_020fe438[];
extern void func_0204c594();
extern void func_02009770();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200a158(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x40
    mov ip, #0x0
    ldr     lr, =data_020fcd18
    mov r7, r0
    mov r6, r1
    add r0, sp, #0x30
    sub r1, ip, #0x1
    mov r5, r2
    mov r4, r3
    str lr, [sp, #0xc]
    str ip, [sp, #0x10]
    str ip, [sp, #0x14]
    str ip, [sp, #0x18]
    str ip, [sp, #0x1c]
    str ip, [sp, #0x20]
    str ip, [sp, #0x24]
    str ip, [sp, #0x28]
    str ip, [sp, #0x2c]
    bl      func_0200af88
    mov ip, #0x0
    ldr     r3, =data_020fe438
    mov r2, #0x5
    add r1, sp, #0x10
    add r0, r5, #0x4
    strb ip, [sp, #0x32]
    str r3, [sp, #0xc]
    str ip, [sp, #0x34]
    str ip, [sp, #0x38]
    str ip, [sp, #0x3c]
    strb r2, [sp, #0x31]
    cmp r1, r0
    beq      L_0200a1f4
    ldr r0, [r5, #0x4]
    str r0, [sp, #0x10]
    ldr r0, [r5, #0x8]
    str r0, [sp, #0x14]
    ldr r0, [r5, #0xc]
    str r0, [sp, #0x18]
    L_0200a1f4:
    ldr lr, [r6, #0x30]
    ldr ip, [r5, #0x30]
    ldr r3, [r6, #0x2c]
    ldr r2, [r5, #0x2c]
    ldr r0, [r5, #0x28]
    ldr r1, [r6, #0x28]
    add r3, r3, r2
    add r2, r1, r0
    add r5, lr, ip
    add r0, sp, #0xc
    add r1, sp, #0x0
    str r2, [sp, #0x0]
    str r3, [sp, #0x4]
    str r5, [sp, #0x8]
    bl      func_0204c594
    add r3, sp, #0xc
    mov r0, r7
    mov r2, r4
    add r1, r6, #0x4
    bl      func_02009770
    add sp, sp, #0x40
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
