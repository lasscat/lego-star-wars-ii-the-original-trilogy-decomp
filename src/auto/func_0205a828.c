#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205a828(s32 *p) {
    stmfd sp!, {r4, lr}
    mov r4, r0
    ldr r0, [r4, #0x28]
    tst r0, #0x1
    add r0, r4, r0, asr #0x1
    ldreq r3, [r4, #0x24]
    beq L_0205a850
    ldr ip, [r0]
    ldr r3, [r4, #0x24]
    ldr r3, [ip, r3]
L_0205a850:
    blx r3
    ldr r1, [r4]
    ldrb r0, [r1, r0]
    ldmia sp!, {r4, pc}
}
// clang-format on
