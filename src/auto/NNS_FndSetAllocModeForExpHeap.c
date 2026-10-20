#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void NNS_FndSetAllocModeForExpHeap(s32 a0, s32 a1) {
    ldrh    r3, [r0, #0x36]
    and     r1, r1, #0x1
    bic     r2, r3, #0x1
    strh    r2, [r0, #0x36]
    ldrh    r2, [r0, #0x36]
    and     r3, r3, #0x1
    orr     r1, r2, r1
    strh    r1, [r0, #0x36]
    mov     r0, r3
    bx      lr
}
// clang-format on
