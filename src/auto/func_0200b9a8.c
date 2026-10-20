#include "m2c.h"

extern void func_0200b998(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200b9a8(s32 a0) {
    stmfd sp!, {r3, lr}
    ldrb r1, [r0, #0x1]
    mov r2, r1, lsl #0x19
    mov r2, r2, lsr #0x19
    cmp r2, #0x3
    addls pc, pc, r2, lsl #0x2
    ldmia sp!, {r3, pc}
L_0200b9c4:
    b L_0200b9d4
    b L_0200b9d8
    b L_0200b9f4
    b L_0200b9d8
L_0200b9d4:
    ldmia sp!, {r3, pc}
L_0200b9d8:
    ldrb r1, [r0, #0x0]
    sub r1, r1, #0x1
    strb r1, [r0, #0x0]
    tst r1, #0xff
    ldmneia sp!, {r3, pc}
    bl func_0200b998
    ldmia sp!, {r3, pc}
L_0200b9f4:
    mov r1, r1, lsl #0x18
    movs r1, r1, lsr #0x1f
    ldrb r1, [r0, #0x0]
    bne L_0200ba28
    add r2, r1, #0x1
    and r1, r2, #0xff
    strb r2, [r0, #0x0]
    cmp r1, #0xf
    ldmneia sp!, {r3, pc}
    ldrb r1, [r0, #0x1]
    orr r1, r1, #0x80
    strb r1, [r0, #0x1]
    ldmia sp!, {r3, pc}
L_0200ba28:
    sub r1, r1, #0x1
    strb r1, [r0, #0x0]
    tst r1, #0xff
    ldreqb r1, [r0, #0x1]
    biceq r1, r1, #0x80
    streqb r1, [r0, #0x1]
    ldmia sp!, {r3, pc}
}
// clang-format on
