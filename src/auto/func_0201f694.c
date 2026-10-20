#include "m2c.h"

extern void func_020b8f70();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201f694(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldrb r0, [r4, #0x1bc]
    cmp r0, #0x1
    cmpne r0, #0x4
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    mov r2, #0x0
    mov r0, r4
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r2, #0x2
    mov r0, #0x32
    mov r1, #0x0
    strb r2, [r4, #0x1bc]
    bl      func_020b8f70
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
