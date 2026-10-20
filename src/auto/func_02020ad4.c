#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02020ad4(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrb r1, [r0, #0x1bc]
    cmp r1, #0x0
    ldmneia   sp!, {r3, pc}
    mov r1, #0x3
    strb r1, [r0, #0x1bc]
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x35
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
