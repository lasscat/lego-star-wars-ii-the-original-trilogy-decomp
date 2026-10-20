#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02011354(s32 a0, s32 a1) {
    stmdb sp!, {r3, lr}
    ldmia r1, {ip, lr}
    smull r3, r2, lr, lr
    smlal r3, r2, ip, ip
    ldr r1, [r1, #0x8]
    smlal r3, r2, r1, r1
    adds r3, r3, #0x800
    adc r1, r2, #0x0
    mov r2, r3, lsr #0xc
    orr r2, r2, r1, lsl #0x14
    str r2, [r0, #0x0]
    ldmfd sp!, {r3, pc}
}
// clang-format on
