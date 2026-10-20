#include "m2c.h"

extern u32 data_0210e9f4[];
extern u32 data_020ff9b4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bedec(s32 a0, s32 a1) {
    ldr r1, [r1, #0x4c]
    ldr r2, =data_0210e9f4
    mov r0, #0xc
    mla r3, r1, r0, r2
    ldr r2, =data_020ff9b4
    cmp r3, r2
    bxeq lr
    ldr r1, [r2, #0x0]
    ldr r0, [r2, #0x4]
    str r1, [r3, #0x0]
    str r0, [r3, #0x4]
    ldr r0, [r2, #0x8]
    str r0, [r3, #0x8]
    bx lr
}
// clang-format on
