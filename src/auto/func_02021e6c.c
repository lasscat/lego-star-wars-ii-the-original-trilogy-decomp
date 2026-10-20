#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02021e6c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldrb r1, [r4, #0x1bc]
    cmp r1, #0x4
    addls pc, pc, r1, lsl #0x2
    b      L_02021f44
    L_02021e88:
    b      L_02021e9c
    b      L_02021f44
    b      L_02021f0c
    b      L_02021f44
    b      L_02021f44
    L_02021e9c:
    add r1, r4, #0x200
    ldrh r1, [r1, #0x12]
    mov r2, #0x0
    mov r3, #0x1
    cmp r1, #0x81
    bne      L_02021ecc
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    blx      ip
    b      L_02021efc
    L_02021ecc:
    cmp r1, #0x82
    str r2, [sp, #0x0]
    bne      L_02021eec
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    blx      ip
    b      L_02021efc
    L_02021eec:
    ldr ip, [r0, #0x0]
    mov r1, #0x5a
    ldr ip, [ip, #0x24]
    blx      ip
    L_02021efc:
    mov r0, #0x1
    add sp, sp, #0x4
    strb r0, [r4, #0x1bc]
    ldmia   sp!, {r3, r4, pc}
    L_02021f0c:
    add r1, r4, #0x200
    ldrh r1, [r1, #0x12]
    cmp r1, #0x81
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x5a
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r0, #0x3
    strb r0, [r4, #0x1bc]
    L_02021f44:
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
