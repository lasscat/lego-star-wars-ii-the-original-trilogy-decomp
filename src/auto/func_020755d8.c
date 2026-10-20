#include "m2c.h"

extern M2C_UNK data_020fec64;

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020755d8(void) {
    mov     r2, #0x10
    mov     r1, r2, asr #0x1
    add     r1, r2, r1, lsr #0x1e
    mov     r3, r1, asr #0x2
    mov     ip, r0
    cmp     r3, #0x0
    bxle    lr
    ldr     r1, =data_020fec64
L_020755f8:
    ldr     r2, [r1, #0x0]
    sub     r3, r3, #0x1
    cmp     r3, #0x0
    str     r2, [ip], #0x4
    bgt     L_020755f8
    bx      lr
}
// clang-format on
