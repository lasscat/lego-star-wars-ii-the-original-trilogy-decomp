#include "m2c.h"

extern void func_02022fa0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02023830(s32 a0) {
    stmdb   sp!, {r3, lr}
    add r1, r0, #0x200
    ldrh r3, [r1, #0x12]
    ldr     r2, =0x15d
    cmp r3, r2
    ldmneia   sp!, {r3, pc}
    ldrh r2, [r1, #0x46]
    ldrh r1, [r0, #0xca]
    strh r2, [sp, #0x0]
    cmp r1, r2
    strneh r2, [r0, #0xca]
    movne r1, #0x1
    strneb r1, [r0, #0xd0]
    bl      func_02022fa0
    ldmia   sp!, {r3, pc}
}
// clang-format on
