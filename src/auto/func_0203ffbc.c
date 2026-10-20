#include "m2c.h"

extern u32 data_020ed2b4[];
extern void func_020accac();
extern void func_02062ae4();
extern void func_02015138();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0203ffbc(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0x64
    ldr     r2, =data_020ed2b4
    mov r1, r0
    ldr r5, [r2, #0x8]
    ldr r4, [r2, #0xc]
    mov lr, #0x1000
    mov ip, #0x0
    add r0, sp, #0x1c
    add r2, sp, #0x0
    add r3, sp, #0x10
    str r5, [sp, #0x8]
    str r4, [sp, #0xc]
    str lr, [sp, #0x10]
    str lr, [sp, #0x14]
    str lr, [sp, #0x18]
    strh ip, [sp, #0x0]
    strh ip, [sp, #0x2]
    strh ip, [sp, #0x4]
    bl      func_020accac
    mov r0, #0x1
    bl      func_02062ae4
    add r1, sp, #0x8
    ldr r0, [r1, r0, lsl #0x2]
    add r2, sp, #0x1c
    mov r1, #0x0
    bl      func_02015138
    mov r1, #0x17
    str r1, [r0, #0x84]
    add sp, sp, #0x64
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
