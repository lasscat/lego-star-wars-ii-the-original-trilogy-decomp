#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202928c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    cmp r1, #0x0
    bne      L_020292a8
    mov r1, #0x0
    sub r1, r1, #0x80000001
    str r1, [r0, #0x0]
    ldmia   sp!, {r3, r4, r5, pc}
    L_020292a8:
    ldr ip, [r1, #0xb4]
    ldr r3, [r2, #0x4]
    ldr r4, [r1, #0xb0]
    sub lr, ip, r3
    smull ip, r3, lr, lr
    ldr lr, [r2, #0x0]
    ldr r5, [r1, #0xb8]
    sub r1, r4, lr
    smlal ip, r3, r1, r1
    ldr r2, [r2, #0x8]
    sub r1, r5, r2
    smlal ip, r3, r1, r1
    mov r1, r3, lsl #0x2
    ldr     r3, =0x40002b0
    mov r2, #0x1
    strh r2, [r3, #0x0]
    mov r2, ip, lsl #0x2
    str r2, [r3, #0x8]
    orr r1, r1, ip, lsr #0x1e
    str r1, [r3, #0xc]
    L_020292f8:
    ldrh r1, [r3, #0x0]
    tst r1, #0x8000
    bne      L_020292f8
    ldr     r1, =0x40002b4
    ldr r1, [r1, #0x0]
    add r1, r1, #0x1
    mov r1, r1, asr #0x1
    str r1, [r0, #0x0]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
