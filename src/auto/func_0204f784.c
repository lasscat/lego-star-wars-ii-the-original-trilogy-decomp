#include "m2c.h"

extern void FX_Div();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204f784(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    ldr lr, [r2, #0xc]
    ldr ip, [r1, #0x8]
    ldr r1, [r1, #0x0]
    smull ip, r4, lr, ip
    adds r5, ip, #0x800
    ldmfd r2, {r2, r3, r6}
    smull r1, ip, r3, r1
    adc r4, r4, #0x0
    adds lr, r1, #0x800
    mov     r5, r5, lsr 0xc
    adc r3, ip, #0x0
    mov     ip, lr, lsr 0xc
    orr r5, r5, r4, lsl #0x14
    orr ip, ip, r3, lsl #0x14
    add r3, ip, r5
    mov r4, r0
    rsb r1, r6, #0x0
    add r0, r3, r2
    bl      FX_Div
    str r0, [r4, #0x0]
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
