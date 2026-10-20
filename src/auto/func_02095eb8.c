#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02095eb8(s32 a0, s32 a1, s32 a2) {
    cmp r1, #0xa
    cmpne r2, #0xa
    moveq r0, #0x0
    bxeq lr
    mov r3, #0xa
    mla r3, r1, r3, r0
    ldrb r1, [r2, r3]
    ldrb r0, [r0, #0xc8]
    cmp r1, r0
    movhi r0, #0x1
    movls r0, #0x0
    bx lr
}
// clang-format on
