#include "m2c.h"

extern void MIi_CheckAnotherAutoDMA();
extern void MIi_CheckDma0SourceAddress();
extern void MIi_DmaSetParams();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 MIi_CardDmaCopy32(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r5, r1
    mov r6, r0
    mov r7, r3
    mvn r1, #0x0
    mov r4, r2
    bl      MIi_CheckAnotherAutoDMA
    mov r0, r6
    mov r1, r5
    mov r2, r7
    mov r3, #0x1000000
    bl      MIi_CheckDma0SourceAddress
    cmp r7, #0x0
    ldmeqia   sp!, {r3, r4, r5, r6, r7, pc}
    add r0, r6, r6, lsl #0x1
    add r0, r0, #0x2
    mov r0, r0, lsl #0x2
    add r0, r0, #0xb0
    add r1, r0, #0x4000000
    L_020cf6e0:
    ldr r0, [r1, #0x0]
    tst r0, #0x80000000
    bne      L_020cf6e0
    ldr     r3, =0xaf000001
    mov r0, r6
    mov r1, r5
    mov r2, r4
    bl      MIi_DmaSetParams
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
