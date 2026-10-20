#include "m2c.h"

extern void func_020bafb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bae80(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r2, #0x8000
    rsb r2, r2, #0x0
    cmp r1, r2
    movlt r1, r2
    cmp r1, #0x8000
    ldr r5, [r0, #0xc]
    movgt r1, #0x8000
    smull ip, r3, r5, r1
    mov r1, #0xa
    mov r2, #0x0
    umull r4, lr, ip, r1
    mla lr, ip, r2, lr
    mla lr, r3, r1, lr
    mov     r1, r4, lsr 0x14
    orr r1, r1, lr, lsl #0xc
    ldr r2, [r0, #0x8]
    add r1, r1, r5
    sub r1, r1, r2
    add r1, r2, r1, asr #0x3
    str r1, [r0, #0x8]
    bl      func_020bafb4
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
