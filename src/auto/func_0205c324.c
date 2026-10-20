#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205c324(s32 a0) {
    mov r2, #0x0
    str r2, [r0, #0x1c]
    str r2, [r0, #0x20]
    ldr r1, =0xffff
    str r2, [r0, #0x24]
    strh r1, [r0, #0x28]
    strh r2, [r0, #0x2a]
    strh r1, [r0, #0x2c]
    strb r2, [r0, #0x2e]
    strb r2, [r0, #0x2f]
    mov r1, r2
L_0205c350:
    str r1, [r0, r2, lsl #0x2]
    add r2, r2, #0x1
    cmp r2, #0x7
    blt L_0205c350
    bx lr
}
// clang-format on
