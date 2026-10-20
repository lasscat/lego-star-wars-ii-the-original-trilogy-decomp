#include "m2c.h"

extern void func_0208e82c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208f0b8(s32 a0) {
    ldr     ip, =0xffffffd8
    add r0, r0, ip
    b       func_0208e82c
}
// clang-format on
