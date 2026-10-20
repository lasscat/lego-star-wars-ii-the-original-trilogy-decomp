#include "m2c.h"

extern void func_020202bc(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020204c0(s32 a0) {
    stmfd sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    add r1, r4, #0x200
    ldrh r1, [r1, #0x12]
    cmp r1, #0x57
    bne L_02020518
    ldrb r1, [r4, #0x1bc]
    cmp r1, #0x6
    addne sp, sp, #0x4
    ldmneia sp!, {r3, r4, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx ip
    mov r0, #0x7
    add sp, sp, #0x4
    strb r0, [r4, #0x1bc]
    ldmia sp!, {r3, r4, pc}
L_02020518:
    mov r1, #0x3
    strb r1, [r4, #0x1bc]
    bl func_020202bc
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
