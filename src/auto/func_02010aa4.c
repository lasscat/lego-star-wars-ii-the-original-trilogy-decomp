#include "m2c.h"

extern void func_02017d24();
extern void func_0205c774();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02010aa4(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    bl      func_02017d24
    ldr r0, [r4, #0x148]
    add r1, sp, #0x0
    cmp r0, #0x0
    ldrne r0, [r0, #0x0]
    add r2, r4, #0x8c
    strne r0, [sp, #0x0]
    moveq r0, #0x0
    streq r0, [sp, #0x0]
    ldr r3, [r1, #0x0]
    ldr r0, [r4, #0x190]
    mov r1, r4
    mov     r3, r3, asr 0xc
    bl      func_0205c774
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
