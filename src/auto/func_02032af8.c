#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02032af8(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrh r1, [r0, #0x16]
    cmp r1, #0xf5
    ldmeqia   sp!, {r3, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r0, #0x4]
    mov r2, #0x1
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x24]
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
