#include "m2c.h"

extern void func_0205e860();
extern u32 data_0211179c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c0e84(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x15]
    cmp r1, #0x0
    beq      L_020c0ea4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx      r1
    L_020c0ea4:
    ldr r0, [r4, #0x18]
    bl      func_0205e860
    ldr r0, [r4, #0x30]
    cmp r0, #0x0
    beq      L_020c0ec0
    ldr r0, [r4, #0x1c]
    bl      func_0205e860
    L_020c0ec0:
    mov r0, #0x0
    str r0, [r4, #0x18]
    str r0, [r4, #0x1c]
    ldr     r0, =data_0211179c
    ldr r2, [r4, #0x4]
    ldr r1, [r0, #0x7b4]
    cmp r1, #0x0
    ldrne r3, [r0, #0x7b8]
    ldreq r3, [r0, #0x7bc]
    ldr     r0, =data_0211179c
    ldr r1, [r0, #0x7bc]
    cmp r3, r1
    ldmeqia   sp!, {r4, pc}
    L_020c0ef4:
    ldr r0, [r3, #0x4]
    cmp r2, r0
    bne      L_020c0f54
    ldr r1, [r3, #0x70]
    cmp r1, #0x0
    ldrne r0, [r3, #0x6c]
    strne r0, [r1, #0x6c]
    ldr r1, [r3, #0x6c]
    cmp r1, #0x0
    ldrne r0, [r3, #0x70]
    strne r0, [r1, #0x70]
    ldr     r0, =data_0211179c
    ldr r1, [r0, #0x7b8]
    cmp r3, r1
    ldreq r1, [r3, #0x6c]
    streq r1, [r0, #0x7b8]
    ldr     r0, =data_0211179c
    ldr r1, [r0, #0x7c0]
    str r1, [r3, #0x6c]
    str r3, [r0, #0x7c0]
    ldr r1, [r0, #0x7b4]
    sub r1, r1, #0x1
    str r1, [r0, #0x7b4]
    ldmia   sp!, {r4, pc}
    L_020c0f54:
    ldr r3, [r3, #0x6c]
    cmp r3, r1
    bne      L_020c0ef4
    ldmia   sp!, {r4, pc}
}
// clang-format on
