#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02095ee8(s32 a0, s32 a1, s32 a2) {
    cmp r1, r2
    bxeq lr
    cmp r1, #0xa
    cmpne r2, #0xa
    bxeq lr
    mov r3, #0xa
    mla r0, r2, r3, r0
    mov r2, #0x64
    strb r2, [r1, r0]
    add r0, r0, r1
    strb r2, [r0, #0x64]
    bx lr
}
// clang-format on
