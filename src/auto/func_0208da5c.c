#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
extern void func_0208d8cc(s32 a0, s32 a1);

asm void func_0208da5c(s32 a0, s32 a1) {
    ldrb    r2, [r1, #0x6c3]
    ldr     ip, =func_0208d8cc
    mov     r1, r0
    mov     r0, r2
    bx      ip
}
// clang-format on
