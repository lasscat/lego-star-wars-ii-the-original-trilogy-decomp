#include "m2c.h"

extern u32 data_020fdbc4[];
extern u32 data_020fddcc[];
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02031f24(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    ldr     r3, =data_020fdbc4
    mov r4, r0
    str r3, [r4, #0x0]
    str r1, [r4, #0x4]
    mov r1, #0x0
    strb r1, [r4, #0xc]
    ldr     r0, =data_020fddcc
    strb r1, [r4, #0xd]
    str r0, [r4, #0x0]
    ldr r0, [sp, #0x1c]
    str r2, [r4, #0x10]
    str r0, [r4, #0x14]
    str r1, [r4, #0x18]
    ldrh r0, [sp, #0x28]
    ldr r1, [sp, #0x20]
    strh r0, [r4, #0x1c]
    ldr r0, [sp, #0x24]
    strh r1, [r4, #0x1e]
    strh r0, [r4, #0x20]
    ldr r1, [r4, #0x4]
    ldrh r2, [r4, #0x20]
    ldr r3, [r1, #0x0]
    add r0, sp, #0x0
    ldr r3, [r3, #0x3c]
    blx      r3
    ldr r1, [sp, #0x0]
    mov r0, r4
    str r1, [r4, #0x18]
    add sp, sp, #0x4
    ldmfd   sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
