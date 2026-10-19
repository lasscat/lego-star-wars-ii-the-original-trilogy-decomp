#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020ce868(s32 a0) {
    b L_020ce86c
L_020ce86c:
    subs r0, r0, #0x4
    bhs L_020ce86c
    bx lr
}
// clang-format on
