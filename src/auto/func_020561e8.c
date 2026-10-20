#include "m2c.h"

extern void func_02067080();
extern u32 data_021090d4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020561e8(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r1
    ldrb r1, [r4, #0x1]
    ldrb r2, [r4, #0x2]
    bl      func_02067080
    cmp r0, #0x0
    ldmeqia   sp!, {r4, pc}
    ldrb r2, [r4, #0x0]
    mov r1, #0xc
    ldr     r3, =data_021090d4
    smulbb r2, r2, r1
    ldr ip, [r3, r2]
    ldr r1, [r0, #0xb0]
    add r3, r3, r2
    cmp r1, ip
    ldreq r2, [r0, #0xb4]
    ldreq r1, [r3, #0x4]
    cmpeq r2, r1
    ldreq r2, [r0, #0xb8]
    ldreq r1, [r3, #0x8]
    cmpeq r2, r1
    movne r1, #0x1
    moveq r1, #0x0
    cmp r1, #0x0
    ldmeqia   sp!, {r4, pc}
    add r1, r0, #0xb0
    cmp r1, r3
    beq      L_0205626c
    str ip, [r0, #0xb0]
    ldr r1, [r3, #0x4]
    str r1, [r0, #0xb4]
    ldr r1, [r3, #0x8]
    str r1, [r0, #0xb8]
    L_0205626c:
    mov r1, #0x1
    strb r1, [r0, #0xd1]
    ldmia   sp!, {r4, pc}
}
// clang-format on
