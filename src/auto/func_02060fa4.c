#include "m2c.h"

extern u32 data_027e03a0[];
extern void func_020610e4();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060fa4(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    add r3, sp, #0x10
    mov lr, r0
    ldr ip, [sp, #0x14]
    mov r2, r1
    ldr r3, [r3, #0x0]
    ldr     r0, =data_027e03a0
    mov r1, lr
    str ip, [sp, #0x0]
    bl      func_020610e4
    mov r0, #0x0
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
