#include "m2c.h"

extern void func_02054168();
extern void func_020548c4();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02054900(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, lr}
    mov r0, r1
    ldr r1, [sp, #0x24]
    mov r4, r3
    mov r5, r2
    bl      func_02054168
    add r3, sp, #0x10
    ldr r1, [r3, #0x0]
    cmp r4, #0x0
    addne r2, r0, r5, lsl #0x6
    addeq r2, r0, r5, lsl #0x5
    ldr ip, [sp, #0x10]
    add r1, r1, #0x2
    str r1, [r3, #0x0]
    ldrh r3, [ip, #0x0]
    ldr r0, [sp, #0x20]
    bl      func_020548c4
    ldmfd   sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
