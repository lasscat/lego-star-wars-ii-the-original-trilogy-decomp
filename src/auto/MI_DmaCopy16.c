#include "m2c.h"

extern void MIi_CheckDma0SourceAddress();
extern void func_01ffd4c8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 MI_DmaCopy16(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    movs r5, r3
    mov r8, r0
    mov r7, r1
    mov r6, r2
    ldmeqia   sp!, {r4, r5, r6, r7, r8, pc}
    mov r2, r5
    mov r3, #0x0
    bl      MIi_CheckDma0SourceAddress
    add r0, r8, r8, lsl #0x1
    add r0, r0, #0x2
    mov r0, r0, lsl #0x2
    add r0, r0, #0xb0
    add r4, r0, #0x4000000
    L_020cec48:
    ldr r0, [r4, #0x0]
    tst r0, #0x80000000
    bne      L_020cec48
    mov r3, r5, lsr #0x1
    mov r0, r8
    mov r1, r7
    mov r2, r6
    orr r3, r3, #0x80000000
    bl      func_01ffd4c8
    L_020cec6c:
    ldr r0, [r4, #0x0]
    tst r0, #0x80000000
    bne      L_020cec6c
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
