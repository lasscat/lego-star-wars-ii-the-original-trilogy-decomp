#include "m2c.h"

extern void func_020534e0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208d3e4(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    bl      func_020534e0
    mov r1, #0x3
    ldr     r0, =0xffff
    strb r1, [r4, #0x8]
    strh r0, [r4, #0xa]
    mov r1, #0x0
    strb r1, [r4, #0xc]
    strb r1, [r4, #0xd]
    mov r0, r4
    strb r1, [r4, #0xe]
    ldmia   sp!, {r4, pc}
}
// clang-format on
