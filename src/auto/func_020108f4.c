#include "m2c.h"

extern void func_020c6240();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020108f4(s32 a0) {
    stmdb   sp!, {r3, lr}
    strb r2, [r0, #0x1b2]
    strb r1, [r0, #0x1b1]
    and r1, r1, #0xff
    strb r1, [r0, #0x1b0]
    mvn r1, #0x0
    strb r1, [r0, #0x1af]
    ldrb r1, [r0, #0x1ae]
    add r3, r0, #0x100
    mov r2, #0x1f0000
    cmp r1, #0x0
    moveq r1, #0x1
    streqb r1, [r0, #0x1af]
    ldrh ip, [r3, #0xa8]
    mov r1, #0x0
    orr ip, ip, #0x20
    strh ip, [r3, #0xa8]
    ldr r3, [r0, #0xdc]
    ldrh r0, [r3, #0xe]
    add r0, r3, r0
    ldr r0, [r0, #0xc]
    add r0, r3, r0
    bl      func_020c6240
    ldmia   sp!, {r3, pc}
}
// clang-format on
