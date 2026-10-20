#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201db50(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldr r1, [r1, #0x0]
    ldrh r2, [r1, #0xc]
    cmp r2, #0x1
    ldmneia   sp!, {r3, pc}
    ldrb r2, [r0, #0x1bc]
    cmp r2, #0x0
    ldmneia   sp!, {r3, pc}
    ldr ip, [r0, #0x0]
    mov r2, #0x0
    ldr ip, [ip, #0x2c]
    mov r3, r2
    blx      ip
    ldmia   sp!, {r3, pc}
}
// clang-format on
