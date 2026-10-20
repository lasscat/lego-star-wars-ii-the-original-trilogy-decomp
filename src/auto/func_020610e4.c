#include "m2c.h"

extern void func_0205e80c();
extern void func_02061c9c();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020610e4(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r1
    mov r4, r2
    mov r0, #0x2c
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    ldmeqfd   sp!, {r3, r4, r5, lr}
    addeq sp, sp, #0x10
    bxeq lr
    add r1, sp, #0x1c
    ldr ip, [sp, #0x20]
    ldr r3, [r1, #0x0]
    mov r1, r5
    mov r2, r4
    str ip, [sp, #0x0]
    bl      func_02061c9c
    ldmfd   sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
