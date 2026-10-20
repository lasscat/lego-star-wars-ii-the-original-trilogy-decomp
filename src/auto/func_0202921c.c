#include "m2c.h"

extern void func_0204a5f8();
extern void func_020291d4();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202921c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    movs r4, r0
    ldmeqfd   sp!, {r4, lr}
    addeq sp, sp, #0x10
    bxeq lr
    add r0, r4, #0xce
    add r1, sp, #0xc
    add r0, r0, #0x500
    bl      func_0204a5f8
    mov r0, r4
    mov r1, #0x40
    bl      func_020291d4
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
