#include "m2c.h"

extern u32 data_020ef580[];
extern void func_0208dad8();
extern u32 data_020f6bab[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208e190(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldrb r2, [r5, #0x6bb]
    mov r0, #0x18
    ldr     r1, =data_020ef580
    smulbb r0, r2, r0
    ldrb r4, [r1, r0]
    cmp r4, #0x20
    bne      L_0208e250
    add r0, r5, #0x600
    ldrh r0, [r0, #0xf0]
    cmp r0, #0xfa
    beq      L_0208e1d4
    bl      func_0208dad8
    ldrh r0, [r0, #0x24]
    cmp r0, #0x1f
    movne r4, r0
    L_0208e1d4:
    cmp r4, #0x20
    bne      L_0208e1f4
    add r0, r5, #0x600
    ldrh r0, [r0, #0xea]
    cmp r0, #0xfa
    beq      L_0208e1f4
    bl      func_0208dad8
    ldrh r4, [r0, #0x28]
    L_0208e1f4:
    ldrb r2, [r5, #0x6c3]
    mov r0, #0x24
    ldr     r1, =data_020f6bab
    smulbb r0, r2, r0
    ldrb r0, [r1, r0]
    cmp r0, #0x3
    addls pc, pc, r0, lsl #0x2
    b      L_0208e250
    L_0208e214:
    b      L_0208e224
    b      L_0208e234
    b      L_0208e224
    b      L_0208e240
    L_0208e224:
    cmp r4, #0x4
    cmpne r4, #0x5
    moveq r4, #0x2
    b      L_0208e250
    L_0208e234:
    cmp r4, #0x2
    moveq r4, #0x0
    b      L_0208e250
    L_0208e240:
    cmp r4, #0x2
    cmpne r4, #0x4
    cmpne r4, #0x5
    moveq r4, #0x0
    L_0208e250:
    mov r0, r4
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
