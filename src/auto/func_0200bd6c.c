#include "m2c.h"

extern void func_0200fe94();
extern u32 data_020fcd98[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200bd6c(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, lr}
    sub sp, sp, #0x4c
    mov r7, #0x0
    mov lr, #0x1000
    mov r6, #0x1
    mov r4, r3
    mov r5, r2
    ldr r3, [sp, #0x60]
    add ip, sp, #0x4
    mov r2, r4
    str r7, [sp, #0x28]
    str r7, [sp, #0x2c]
    str r7, [sp, #0x30]
    str lr, [sp, #0x34]
    str lr, [sp, #0x38]
    str lr, [sp, #0x3c]
    strh r7, [sp, #0x40]
    strh r7, [sp, #0x42]
    strh r7, [sp, #0x44]
    strb r6, [sp, #0x48]
    strb r6, [sp, #0x49]
    mov r6, r0
    str ip, [sp, #0x0]
    bl      func_0200fe94
    ldr     r0, =data_020fcd98
    mov r1, r7
    str r0, [r6, #0x0]
    ldr r2, [r5, #0x0]
    mov r0, r6
    str r2, [r6, #0x1bc]
    ldr r2, [r5, #0x4]
    str r2, [r6, #0x1c0]
    ldr r2, [r5, #0x8]
    str r2, [r6, #0x1c4]
    strb r1, [r6, #0x1d0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x3c]
    blx      r1
    ldr     r0, =0x276
    cmp r4, r0
    ldreq r0, [r6, #0x8]
    biceq r0, r0, #0x1
    streq r0, [r6, #0x8]
    mov r0, r6
    add sp, sp, #0x4c
    ldmia   sp!, {r4, r5, r6, r7, pc}
}
// clang-format on
