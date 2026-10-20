#include "m2c.h"

extern u32 data_021044a4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205eacc(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    ldr     r4, =data_021044a4
    ldrb r5, [r4, #0x0]
    mov r5, r5, lsl #0x1b
    movs r5, r5, lsr #0x1f
    beq      L_0205eb60
    cmp r1, #0x0
    ldrh lr, [r4, #0x2a]
    ldrh r4, [r4, #0x2c]
    mov ip, #0x0
    bls      L_0205eb60
    ldr r0, [r0, #0x0]
    L_0205eafc:
    ldr r5, [r0, ip, lsl #0x2]
    ldr r5, [r5, #0x8]
    and r5, r5, #0x1
    cmp r5, #0x1
    bne      L_0205eb54
    ldr r5, [r0, ip, lsl #0x2]
    ldr r6, [r5, #0x50]
    ldr r5, [r5, #0x4c]
    mov r7, r6, asr #0xc
    mov r6, r5, lsl #0x4
    cmp lr, r6, lsr #0x10
    mov r5, r7, lsl #0x10
    blo      L_0205eb54
    add r6, r2, r6, lsr #0x10
    cmp lr, r6
    bge      L_0205eb54
    cmp r4, r5, lsr #0x10
    blo      L_0205eb54
    add r5, r3, r5, lsr #0x10
    cmp r4, r5
    movlt r0, ip
    ldmltia   sp!, {r3, r4, r5, r6, r7, pc}
    L_0205eb54:
    add ip, ip, #0x1
    cmp ip, r1
    blo      L_0205eafc
    L_0205eb60:
    mvn r0, #0x0
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
