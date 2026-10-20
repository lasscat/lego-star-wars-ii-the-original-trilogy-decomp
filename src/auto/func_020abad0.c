#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020abad0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldrh r0, [r1, #0x2]
    mov lr, #0x0
    add ip, r1, r0
    ldrb r0, [ip, #0x1]
    cmp r0, #0x0
    bls      L_020abbb8
    L_020abaec:
    ldrh r4, [r2, #0x34]
    ldrh r3, [ip, #0x6]
    ldr r0, [r2, #0x2c]
    add r5, r2, r4
    ldrh r4, [r5, #0x6]
    ldrh r6, [ip, r3]
    add r8, ip, r3
    ldrh r3, [r5, r4]
    add r4, r5, r4
    mov r5, r0, lsl #0x10
    mul r0, r3, lr
    add r3, r4, #0x4
    add r4, r3, r0
    ldrh r4, [r4, #0x2]
    mul r7, r6, lr
    add r8, r8, #0x4
    ldrh r6, [r8, r7]
    tst r4, #0x1
    add r4, r8, r7
    add r6, r1, r6
    mov r7, r5, lsr #0x10
    ldrh r8, [r3, r0]
    bne      L_020abb58
    mov r0, r8, lsl #0xf
    mov r3, r7, lsl #0xf
    mov r8, r0, lsr #0x10
    mov r7, r3, lsr #0x10
    L_020abb58:
    ldrb r0, [r4, #0x2]
    mov r5, #0x0
    cmp r0, #0x0
    ble      L_020abba8
    add r0, r8, r7
    mov r0, r0, lsl #0x10
    add r3, r1, #0x4
    mov r0, r0, lsr #0x10
    L_020abb78:
    ldrh r9, [r1, #0xa]
    ldrb r7, [r6, r5]
    add r5, r5, #0x1
    ldrh r8, [r3, r9]
    add r9, r3, r9
    mla r7, r8, r7, r9
    ldr r7, [r7, #0x4]
    add r7, r1, r7
    strh r0, [r7, #0x1c]
    ldrb r7, [r4, #0x2]
    cmp r5, r7
    blt      L_020abb78
    L_020abba8:
    ldrb r0, [ip, #0x1]
    add lr, lr, #0x1
    cmp lr, r0
    blo      L_020abaec
    L_020abbb8:
    mov r0, #0x1
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
