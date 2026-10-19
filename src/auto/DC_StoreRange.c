#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void DC_StoreRange(void) {
    add r1, r1, r0
    bic r0, r0, #0x1f
    b L_020cdd2c
L_020cdd2c:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt L_020cdd2c
    bx lr
}
// clang-format on
