#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202c698(s32 a0, s32 a1, s32 a2) {
    stmfd sp!, {r4, lr}
    mov r4, r1
    cmp r2, #0x0
    beq L_0202c6f0
    ldrb r0, [r4, #0xc]
    tst r0, #0x4
    orr r1, r0, #0x2
    mov r0, r4
    bne L_0202c6dc
    strb r1, [r4, #0xc]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx r1
    ldrb r0, [r4, #0xc]
    orr r0, r0, #0x4
    strb r0, [r4, #0xc]
    ldmia sp!, {r4, pc}
L_0202c6dc:
    strb r1, [r4, #0xc]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x14]
    blx r1
    ldmia sp!, {r4, pc}
L_0202c6f0:
    ldrb r1, [r4, #0xc]
    mov r0, r4
    bic r1, r1, #0x2
    strb r1, [r4, #0xc]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x10]
    blx r1
    ldmia sp!, {r4, pc}
}
// clang-format on
