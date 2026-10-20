#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208c6ac(s32 a0, s32 a1, s32 a2) {
    cmp r1, #0x10
    movhs r0, #0x0
    bxhs lr
    mov r3, #0xb
    mla r2, r1, r3, r2
    mov r1, r2, asr #0x5
    ldr r1, [r0, r1, lsl #0x2]
    and r2, r2, #0x1f
    mov r0, #0x1
    tst r1, r0, lsl r2
    moveq r0, #0x0
    bx lr
}
// clang-format on
