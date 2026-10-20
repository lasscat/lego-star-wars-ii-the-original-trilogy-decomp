#include "m2c.h"

extern void func_02084b1c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02084bf4(s32 a0) {
    ldr     ip, =0xffffffd8
    add r0, r0, ip
    b       func_02084b1c
}
// clang-format on
