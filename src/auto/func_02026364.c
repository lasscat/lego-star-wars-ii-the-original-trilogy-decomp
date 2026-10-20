#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02026364(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r2, r0
    ldr r0, [r1, #0x0]
    ldrh r1, [r0, #0xc]
    cmp r1, #0x1
    cmpne r1, #0x2
    ldmneia   sp!, {r3, pc}
    ldrb r1, [r2, #0x217]
    cmp r1, #0x0
    ldmeqia   sp!, {r3, pc}
    ldr ip, [r0, #0x0]
    mov r1, r2
    ldr ip, [ip, #0x2c]
    mov r2, #0xa
    mov r3, #0x0
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
