#include "m2c.h"

extern void func_0202c698();
extern void func_0202c374();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202c948(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r2, [r5, #0x20]
    mov r4, r1
    cmp r2, #0x0
    moveq r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    ldrb r2, [r4, #0xc]
    tst r2, #0x1
    bne      L_0202c990
    tst r2, #0x2
    bne      L_0202c990
    mov r2, #0x1
    bl      func_0202c698
    ldrb r2, [r4, #0xc]
    tst r2, #0x2
    moveq r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    L_0202c990:
    tst r2, #0x1
    bne      L_0202c9a8
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx      r1
    L_0202c9a8:
    ldrb r0, [r4, #0xc]
    tst r0, #0x1
    beq      L_0202c9dc
    mov r0, r5
    mov r1, r4
    bl      func_0202c374
    mov r0, r5
    mov r1, r4
    mov r2, #0x0
    bl      func_0202c698
    ldrb r0, [r4, #0xc]
    orr r0, r0, #0x1
    strb r0, [r4, #0xc]
    L_0202c9dc:
    ldrb r0, [r4, #0xc]
    tst r0, #0x1
    moveq r0, #0x1
    movne r0, #0x0
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
