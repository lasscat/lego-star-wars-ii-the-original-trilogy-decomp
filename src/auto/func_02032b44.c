#include "m2c.h"

extern u32 data_020fdbc4[];
extern u32 data_020fde5c[];
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02032b44(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    ldr     r3, =data_020fdbc4
    mov lr, #0x0
    str r3, [r0, #0x0]
    str r1, [r0, #0x4]
    strb lr, [r0, #0xc]
    ldr     r1, =data_020fde5c
    strb lr, [r0, #0xd]
    str r1, [r0, #0x0]
    ldr r1, [r2, #0x0]
    ldr r3, [sp, #0x14]
    str r1, [r0, #0x10]
    ldr ip, [r2, #0x4]
    ldr r1, [sp, #0x28]
    str ip, [r0, #0x14]
    ldr ip, [r2, #0x8]
    ldr r2, [sp, #0x1c]
    str ip, [r0, #0x18]
    str r3, [r0, #0x1c]
    str lr, [r0, #0x20]
    str lr, [r0, #0x24]
    str lr, [r0, #0x28]
    str r1, [r0, #0x2c]
    ldr r1, [sp, #0x20]
    strh r2, [r0, #0x38]
    ldr r2, [sp, #0x24]
    strh r1, [r0, #0x3a]
    ldrb r1, [sp, #0x18]
    strb r2, [r0, #0x3c]
    strb r1, [r0, #0x3d]
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
