#include "m2c.h"

extern u32 data_02109358[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209ce9c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r2, #0xc
    mul r8, r1, r2
    add r6, r0, r8
    ldr     r3, =data_02109358
    add r2, r0, #0x34
    ldr r3, [r3, r1, lsl #0x2]
    add ip, r2, r8
    add r9, r3, #0xb0
    ldr r5, [r6, #0x3c]
    ldmib r9, {r4, r7}
    ldr lr, [r6, #0x38]
    ldr r3, [r3, #0xb0]
    ldr r2, [r2, r8]
    sub r5, r7, r5
    cmp ip, r9
    sub r4, r4, lr
    sub r7, r3, r2
    beq      L_0209cefc
    str r3, [ip, #0x0]
    ldr r2, [r9, #0x4]
    str r2, [r6, #0x38]
    ldr r2, [r9, #0x8]
    str r2, [r6, #0x3c]
    L_0209cefc:
    smull lr, r2, r4, r4
    smlal lr, r2, r7, r7
    smlal lr, r2, r5, r5
    mov r2, r2, lsl #0x2
    ldr     ip, =0x40002b0
    mov r3, #0x1
    strh r3, [ip, #0x0]
    mov r3, lr, lsl #0x2
    str r3, [ip, #0x8]
    orr r2, r2, lr, lsr #0x1e
    str r2, [ip, #0xc]
    L_0209cf28:
    ldrh r2, [ip, #0x0]
    tst r2, #0x8000
    bne      L_0209cf28
    ldr     r2, =0x40002b4
    add r3, r0, r1, lsl #0x2
    ldr r0, [r2, #0x0]
    ldr r1, [r3, #0x24]
    add r0, r0, #0x1
    add r0, r1, r0, asr #0x1
    str r0, [r3, #0x24]
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
