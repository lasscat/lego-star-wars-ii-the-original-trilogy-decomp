#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02021b24(s32 a0) {
    stmdb   sp!, {r3, lr}
    add r1, r0, #0x200
    ldrh r1, [r1, #0x12]
    cmp r1, #0xe3
    ldmneia   sp!, {r3, pc}
    ldrb r1, [r0, #0x1bc]
    cmp r1, #0x0
    ldmeqia   sp!, {r3, pc}
    mov r1, #0x4
    strb r1, [r0, #0x1bc]
    mov r3, #0x1
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r2, #0x0
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
