#include "m2c.h"

extern void func_02010384();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200bfec(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    add r1, sp, #0xc
    ldr r1, [r1, #0x0]
    mov r4, r0
    bl      func_02010384
    ldrb r0, [r4, #0x1d0]
    cmp r0, #0x0
    ldmeqfd   sp!, {r4, lr}
    addeq sp, sp, #0x10
    bxeq lr
    mov r0, r4
    ldr r2, [r0, #0x0]
    ldr r1, [r4, #0x1cc]
    ldr r2, [r2, #0x40]
    blx      r2
    mov r0, #0x0
    strb r0, [r4, #0x1d0]
    str r0, [r4, #0x1cc]
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
