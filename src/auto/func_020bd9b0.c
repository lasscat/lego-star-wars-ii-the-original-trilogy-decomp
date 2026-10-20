#include "m2c.h"

extern void func_020bd884();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bd9b0(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    mov r4, r0
    ldr r1, [r4, #0x68]
    add r0, r4, #0x48
    mov     r1, r1, lsl 0x1
    mov r2, #0x1
    str r1, [sp, #0x8]
    bl      func_020bd884
    ldr r1, [r4, #0x6c]
    add r0, r4, #0x50
    mov     r1, r1, lsl 0x1
    mov r2, #0x1
    str r1, [sp, #0x4]
    bl      func_020bd884
    ldr r1, [r4, #0x70]
    add r0, r4, #0x58
    mov     r1, r1, lsl 0x1
    mov r2, #0x1
    str r1, [sp, #0x0]
    bl      func_020bd884
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
