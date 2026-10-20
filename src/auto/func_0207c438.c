#include "m2c.h"

extern void func_0207c018();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207c438(s32 a0) {
    ldr     ip, =0xffffffd8
    add r0, r0, ip
    b       func_0207c018
}
// clang-format on
