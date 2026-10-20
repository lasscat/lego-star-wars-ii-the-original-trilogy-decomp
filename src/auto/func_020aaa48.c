#include "m2c.h"

extern void func_0205e84c(s32);

// clang-format off
asm void func_020aaa48(s32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    mov     r5, r0
    ldr     r4, [r5, #0x398]
    cmp     r4, #0x0
    beq     L_020aaa78
L_020aaa5c:
    ldr     r0, [r4, #0x0]
    cmp     r0, #0x0
    beq     L_020aaa6c
    bl      func_0205e84c
L_020aaa6c:
    ldr     r4, [r4, #0x4]
    cmp     r4, #0x0
    bne     L_020aaa5c
L_020aaa78:
    add     r0, r5, #0x394
    ldr     r1, [r0, #0x0]
    ldr     r1, [r1, #0x18]
    blx     r1
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
