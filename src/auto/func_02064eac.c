#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02064eac(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov lr, #0x1
    mov r4, #0x0
    mov ip, lr
    b      L_02064f20
    L_02064ec0:
    mov r4, r2
    mov lr, r1
    cmp r1, #0x0
    ble      L_02064f20
    L_02064ed0:
    ldrb r3, [r0, r2, lsr #0x3]
    cmp r3, #0xff
    addeq r2, r2, #0x8
    beq      L_02064f20
    cmp r3, #0x0
    addeq r2, r2, #0x8
    subeq lr, lr, #0x8
    beq      L_02064f18
    and r5, r2, #0x7
    L_02064ef4:
    tst r3, ip, lsl r5
    add r2, r2, #0x1
    bne      L_02064f20
    add r5, r5, #0x1
    cmp r5, #0x8
    sub lr, lr, #0x1
    bhs      L_02064f18
    cmp lr, #0x0
    bgt      L_02064ef4
    L_02064f18:
    cmp lr, #0x0
    bgt      L_02064ed0
    L_02064f20:
    add r3, r2, r1
    cmp r3, #0x400
    bhi      L_02064f34
    cmp lr, #0x0
    bgt      L_02064ec0
    L_02064f34:
    cmp lr, #0x0
    movle r0, r4
    ldrgt     r0, =0xffff
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
