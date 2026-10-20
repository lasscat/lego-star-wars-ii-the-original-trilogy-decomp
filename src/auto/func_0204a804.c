#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204a804(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrh r2, [r0, #0x0]
    add r0, r1, #0x100
    ldrh r0, [r0, #0x82]
    tst r2, #0xc0
    beq      L_0204a84c
    cmp r0, #0x6
    cmpne r0, #0xb
    ldmeqia   sp!, {r3, pc}
    mov r3, #0x0
    mov r0, r1
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x6
    ldr ip, [ip, #0x24]
    mov r2, #0x1
    blx      ip
    ldmia   sp!, {r3, pc}
    L_0204a84c:
    tst r2, #0x30
    cmpne r0, #0x1
    cmpne r0, #0xa
    ldmeqia   sp!, {r3, pc}
    mov r3, #0x0
    mov r0, r1
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x1
    ldr ip, [ip, #0x24]
    mov r2, r1
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
