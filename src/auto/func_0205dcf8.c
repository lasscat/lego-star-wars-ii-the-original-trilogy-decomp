#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205dcf8(s32 a0, s32 a1, s32 a2) {
    cmp     r2, #0x3
    mov     r0, #0x0
    addls   pc, pc, r2, lsl #0x2
    bx      lr
L_0205dd08:
    b       L_0205dd18
    b       L_0205dd18
    b       L_0205dd74
    b       L_0205dd74
L_0205dd18:
    cmp     r1, #0x0
    bxeq    lr
    mov     r0, r1
    cmp     r2, #0x0
    bne     L_0205dd34
    ldr     r1, [r1, #0xc]
    b       L_0205dd38
L_0205dd34:
    ldr     r1, [r1, #0x8]
L_0205dd38:
    cmp     r1, #0x0
    subne   r1, r1, #0x4
    cmp     r1, #0x0
    bxeq    lr
L_0205dd48:
    mov     r0, r1
    cmp     r2, #0x0
    bne     L_0205dd5c
    ldr     r1, [r1, #0xc]
    b       L_0205dd60
L_0205dd5c:
    ldr     r1, [r1, #0x8]
L_0205dd60:
    cmp     r1, #0x0
    subne   r1, r1, #0x4
    cmp     r1, #0x0
    bne     L_0205dd48
    bx      lr
L_0205dd74:
    cmp     r1, #0x0
    bxeq    lr
    mov     r0, r1
    cmp     r2, #0x2
    ldreq   r1, [r1, #0x14]
    ldrne   r1, [r1, #0x10]
    cmp     r1, #0x0
    bxeq    lr
L_0205dd94:
    mov     r0, r1
    cmp     r2, #0x2
    ldreq   r1, [r1, #0x14]
    ldrne   r1, [r1, #0x10]
    cmp     r1, #0x0
    bne     L_0205dd94
    bx      lr
}
// clang-format on
