#include "m2c.h"

extern u32 data_020fdbc4[];
extern u32 data_020fddf0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020324d4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    ldr r3, =data_020fdbc4
    mov r2, #0x0
    str r3, [r0, #0x0]
    str r1, [r0, #0x4]
    strb r2, [r0, #0xc]
    ldr r1, =data_020fddf0
    strb r2, [r0, #0xd]
    str r1, [r0, #0x0]
    ldrh r1, [sp, #0x8]
    str r2, [r0, #0x10]
    strh r1, [r0, #0x14]
    strb r2, [r0, #0x16]
    add sp, sp, #0x10
    bx lr
}
// clang-format on
