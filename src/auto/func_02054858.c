#include "m2c.h"

extern void func_0205e6e0();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02054858(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    add r4, sp, #0xc
    ldr r1, [r4, #0x0]
    ldr ip, [sp, #0xc]
    mov     r3, r2, lsl 0x15
    add r2, r1, #0x2
    str r2, [r4, #0x0]
    ldrh lr, [ip, #0x0]
    add ip, r2, #0x2
    str ip, [r4, #0x0]
    ldrh r1, [ip, #0x0]
    ldrh r2, [r2, #0x0]
    ldrh ip, [ip, #0x2]
    mov     r1, r1, lsl 0xc
    orr r2, r2, lr, lsl #0x10
    str r1, [r0, #0x0]
    mov     r1, ip, lsl 0xc
    str r1, [r0, #0x4]
    ldr r0, [sp, #0xc]
    add r1, r0, #0x4
    add r0, r3, #0x6000000
    str r1, [sp, #0xc]
    bl      func_0205e6e0
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
