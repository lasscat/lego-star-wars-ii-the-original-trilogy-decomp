#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02020b0c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    cmp r1, #0x3
    mov r4, r0
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    add r2, r4, #0x200
    ldrh r3, [r2, #0x12]
    ldr     r2, =0x143
    cmp r3, r2
    addne sp, sp, #0x4
    strneb r1, [r4, #0x1bc]
    ldmneia   sp!, {r3, r4, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x58
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r0, #0x2
    strb r0, [r4, #0x1bc]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
