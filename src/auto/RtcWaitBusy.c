#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
extern s32 data_021174f8;

asm void RtcWaitBusy(void) {
    ldr     ip, =data_021174f8
    b       L_020d4bf0
L_020d4bf0:
    ldr     r0, [ip, #0x0]
    cmp     r0, #0x1
    beq     L_020d4bf0
    bx      lr
}
// clang-format on
