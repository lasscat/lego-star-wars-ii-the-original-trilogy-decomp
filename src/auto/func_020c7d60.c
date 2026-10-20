#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c7d60(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr r5, [r1, #0x18]
    mov r2, #0x0
    str r5, [r0, #0x0]
    ldr r3, [r1, #0x1c]
    str r3, [r0, #0x14]
    str r2, [r0, #0x4]
    ldr r4, [r1, #0x24]
    mov     ip, r3, lsl 0x1
    smull lr, r4, r5, r4
    mov     lr, lr, lsr 0x8
    orr lr, lr, r4, lsl #0x18
    ldrh r5, [r1, #0x2c]
    rsb r4, lr, #0x0
    rsb lr, ip, #0x0
    mul r4, r5, r4
    str r4, [r0, #0x30]
    ldr ip, [r1, #0x28]
    ldrh r4, [r1, #0x2e]
    smull ip, r1, r3, ip
    mov     r3, ip, lsr 0x8
    add ip, lr, #0x2000
    orr r3, r3, r1, lsl #0x18
    mul ip, r4, ip
    mul r1, r4, r3
    add r1, r1, ip, lsl #0x3
    str r1, [r0, #0x34]
    str r2, [r0, #0x10]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
