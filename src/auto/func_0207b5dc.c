#include "m2c.h"

extern u32 data_020ff02c[];
extern u32 data_020ff02e[];
extern u32 data_020ff024[];
extern u32 data_020ee670[];
extern void func_02054c80();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207b5dc(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0x24
    mov r3, #0x18
    mul ip, r1, r3
    mov     lr, r1, lsl 0x2
    ldr     r5, =data_020ff02c
    ldr     r4, =data_020ff02e
    ldrsh r5, [r5, lr]
    ldrsh lr, [r4, lr]
    add ip, ip, #0x1
    strh r5, [sp, #0x18]
    strh lr, [sp, #0x1a]
    str ip, [sp, #0x0]
    mov r3, #0x40
    str r3, [sp, #0x4]
    mov lr, #0x0
    str lr, [sp, #0x8]
    mov ip, r0
    ldr     r4, =data_020ff024
    str lr, [sp, #0xc]
    add r0, sp, #0x18
    str r0, [sp, #0x10]
    add lr, r4, r2, lsl #0x2
    ldrb r4, [r4, r2, lsl #0x2]
    ldrb r2, [lr, #0x1]
    ldr     r0, =data_020ee670
    mov     r1, r1, lsl 0x1
    strb r4, [sp, #0x14]
    strb r2, [sp, #0x15]
    ldrb r4, [lr, #0x2]
    ldrb lr, [lr, #0x3]
    ldrh r2, [r0, r1]
    add r0, sp, #0x1c
    strb r4, [sp, #0x16]
    strb lr, [sp, #0x17]
    ldr r1, [ip, #0x14]
    add r3, r3, #0xcd
    bl      func_02054c80
    add sp, sp, #0x24
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
