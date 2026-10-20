#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02023c2c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    add r1, r4, #0x200
    ldrh r1, [r1, #0x12]
    cmp r1, #0x14
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    mov r2, #0x0
    strb r2, [r4, #0x1bc]
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x8a
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r0, #0x0
    str r0, [r4, #0x21c]
    str r0, [r4, #0x218]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
