#include "m2c.h"

extern void NNS_G3dGlbGetInvV();
extern void MTX_Concat43();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200c6d4(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x30
    mov r6, r0
    mov r5, r1
    mov r4, r2
    bl      NNS_G3dGlbGetInvV
    add r3, r6, #0x39c
    mov r2, #0x38
    mov r1, r0
    mla r0, r5, r2, r3
    add r2, sp, #0x0
    bl      MTX_Concat43
    ldr r0, [sp, #0x24]
    str r0, [r4, #0x0]
    ldr r0, [sp, #0x28]
    str r0, [r4, #0x4]
    ldr r0, [sp, #0x2c]
    str r0, [r4, #0x8]
    add sp, sp, #0x30
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
