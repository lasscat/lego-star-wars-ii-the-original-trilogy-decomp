#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201dabc(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    mov r4, r0
    blx     ip
    mov r0, #0x2
    strb r0, [r4, #0x1bc]
    ldr r0, [r4, #0x8]
    orr r0, r0, #0x1
    str r0, [r4, #0x8]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
