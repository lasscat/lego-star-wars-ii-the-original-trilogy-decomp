#include "m2c.h"

// clang-format off
asm void func_0201db00(s32 *arg0, s32 *arg1) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldr r0, [r1, #0x0]
    ldrh r1, [r0, #0xc]
    cmp r1, #0x1
    beq L_0201db20
    cmp r1, #0x4
    ldmia sp!, {r4, pc}
L_0201db20:
    ldrb r1, [r4, #0x216]
    cmp r1, #0x0
    ldmneia sp!, {r4, pc}
    ldr ip, [r0, #0x0]
    mov r2, #0x0
    ldr ip, [ip, #0x2c]
    mov r1, r4
    mov r3, r2
    blx ip
    mov r0, #0x1
    strb r0, [r4, #0x1bc]
    ldmia sp!, {r4, pc}
}
// clang-format on
