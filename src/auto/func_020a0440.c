#include "m2c.h"

extern void func_020a0630();
extern void func_020a9158();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020a0440(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    add r1, sp, #0xc
    ldr r1, [r1, #0x0]
    mov r4, r0
    bl      func_020a0630
    mov r0, r4
    bl      func_020a9158
    ldr r0, [r4, #0x200]
    add r0, r0, #0x1
    str r0, [r4, #0x200]
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
