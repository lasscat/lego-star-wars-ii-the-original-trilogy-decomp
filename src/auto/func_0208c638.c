#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208c638(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r3, lr}
    mov     r3, #0xb
    mla     r2, r1, r3, r2
    mov     r3, r2, asr #0x5
    and     ip, r2, #0x1f
    mov     lr, #0x1
    mvn     r1, lr, lsl ip
    ldr     r2, [r0, r3, lsl #0x2]
    and     r2, r2, r1
    orr     r1, r2, lr, lsl ip
    str     r1, [r0, r3, lsl #0x2]
    ldrb    r1, [r0, #0x19]
    add     r1, r1, #0x1
    strb    r1, [r0, #0x19]
    ldmia   sp!, {r3, pc}
}
// clang-format on
