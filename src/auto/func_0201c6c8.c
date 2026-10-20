#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201c6c8(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldrb r0, [r4, #0xa4]
    cmp r0, #0x0
    ldmeqia   sp!, {r4, pc}
    ldr r0, [r4, #0x80]
    ldr r2, [r4, #0x8c]
    ldr ip, [r0, #0x0]
    ldr r3, [r4, #0x90]
    ldr ip, [ip, #0x8]
    mov r1, r4
    blx      ip
    ldrb r2, [r4, #0xa5]
    mov r1, r0
    cmp r1, r2
    ldmeqia   sp!, {r4, pc}
    mov r0, r4
    strb r1, [r4, #0xa5]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x2c]
    blx      r2
    ldmia   sp!, {r4, pc}
}
// clang-format on
