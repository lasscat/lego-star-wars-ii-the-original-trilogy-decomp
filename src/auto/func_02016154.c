#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02016154(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r2, r0
    ldrb r0, [r2, #0x1c0]
    cmp r0, #0x0
    ldmneia   sp!, {r3, pc}
    ldr r0, [r1, #0x0]
    ldrh r0, [r0, #0xc]
    cmp r0, #0x1
    ldmneia   sp!, {r3, pc}
    mov r0, #0x1
    strb r0, [r2, #0x1c0]
    mov r0, #0x19
    strb r0, [r2, #0x214]
    ldr r0, [r1, #0x0]
    mov r1, r2
    ldr ip, [r0, #0x0]
    mov r2, #0xa
    ldr ip, [ip, #0x2c]
    mov r3, #0x0
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
