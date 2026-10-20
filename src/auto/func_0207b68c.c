#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207b68c(s32 a0) {
    cmp     r0, #0x28
    bgt     L_0207b6ec
    subs    r1, r0, #0x23
    addpl   pc, pc, r1, lsl #0x2
    b       L_0207b6b8
    b       L_0207b70c
    b       L_0207b70c
    b       L_0207b70c
    b       L_0207b70c
    b       L_0207b70c
    b       L_0207b70c
L_0207b6b8:
    cmp     r0, #0xe
    bgt     L_0207b6e0
    cmp     r0, #0xb
    blt     L_0207b6d4
    cmpne   r0, #0xe
    beq     L_0207b70c
    b       L_0207b714
L_0207b6d4:
    cmp     r0, #0x1
    beq     L_0207b70c
    b       L_0207b714
L_0207b6e0:
    cmp     r0, #0x1c
    beq     L_0207b70c
    b       L_0207b714
L_0207b6ec:
    cmp     r0, #0x45
    bgt     L_0207b704
    bge     L_0207b70c
    cmp     r0, #0x30
    beq     L_0207b70c
    b       L_0207b714
L_0207b704:
    cmp     r0, #0x46
    bne     L_0207b714
L_0207b70c:
    mov     r0, #0x1
    bx      lr
L_0207b714:
    mov     r0, #0x0
    bx      lr
}
// clang-format on
