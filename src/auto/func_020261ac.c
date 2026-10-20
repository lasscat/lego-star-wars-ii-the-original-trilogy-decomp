#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020261ac(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov     r2, #0x1
    strb    r2, [r0, #0x1bc]
    add     r1, r0, #0x200
    ldrh    r1, [r1, #0x12]
    cmp     r1, #0xed
    mov     r1, #0x0
    bne     L_020261e0
    ldr     r2, [r0, #0x8]
    bic     r2, r2, #0x1
    str     r2, [r0, #0x8]
    strb    r1, [r0, #0x217]
    ldmia   sp!, {r3, pc}
L_020261e0:
    str     r1, [sp, #0x0]
    ldr     ip, [r0, #0x0]
    mov     r3, r2
    ldr     ip, [ip, #0x24]
    mov     r1, #0x8b
    blx     ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
