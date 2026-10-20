#include "m2c.h"

extern void func_02069514();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02069da8(s32 a0) {
    ldr     ip, =0xfffffff4
    add r0, r0, ip
    b       func_02069514
}
// clang-format on
