#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02021b6c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r0, [r1, #0x0]
    ldrh r1, [r0, #0xc]
    cmp r1, #0x1
    cmpne r1, #0x2
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    ldr ip, [r0, #0x0]
    mov r1, r4
    ldr ip, [ip, #0x2c]
    mov r2, #0xa
    mov r3, #0x0
    blx      ip
    add r0, r4, #0x200
    ldrh r1, [r0, #0x12]
    ldr     r0, =0x14e
    cmp r1, r0
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    ldr r0, [r4, #0x8]
    mov r3, #0x1
    orr r0, r0, #0x800
    str r0, [r4, #0x8]
    mov r0, r4
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r2, #0x0
    blx      ip
    mov r0, #0x5
    strb r0, [r4, #0x1bc]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
