#include "m2c.h"

extern u32 data_020fe5dc[];
extern void func_0205df2c();
extern void func_0205d3f4();
extern void func_0205e84c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205d764(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r1, =data_020fe5dc
    mov r4, r0
    str r1, [r4, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx      r1
    add r0, r4, #0x14
    bl      func_0205df2c
    mov r0, r4
    bl      func_0205d3f4
    mov r0, r4
    bl      func_0205e84c
    mov r0, r4
    ldmia   sp!, {r4, pc}
}
// clang-format on
