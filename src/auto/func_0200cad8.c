#include "m2c.h"

extern void func_02010384();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200cad8(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    add r1, r0, #0x100
    ldrh r1, [r1, #0x4e]
    mov     r1, r1, lsl 0x1e
    mov     r1, r1, lsr 0x1f
    cmp r1, #0x1
    ldreq r1, [r0, #0x8]
    orreq r1, r1, #0x2
    streq r1, [r0, #0x8]
    add r1, sp, #0xc
    ldr r1, [r1, #0x0]
    bl      func_02010384
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
