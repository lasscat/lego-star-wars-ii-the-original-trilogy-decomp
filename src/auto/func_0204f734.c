#include "m2c.h"

extern void func_0204f760();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204f734(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldr r2, [r2, #0x10]
    ldr r1, [r3, #0x30]
    smull r3, r1, r2, r1
    adds r3, r3, #0x800
    adc r2, r1, #0x0
    mov     r1, r3, lsr 0xc
    orr r1, r1, r2, lsl #0x14
    str r1, [sp, #0x0]
    bl      func_0204f760
    ldmia   sp!, {r3, pc}
}
// clang-format on
