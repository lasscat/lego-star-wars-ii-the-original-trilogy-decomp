#include "m2c.h"

extern void func_0205ab44();
extern void func_0201b07c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201af8c(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x18]
    sub r1, r1, #0x1
    strb r1, [r4, #0x18]
    tst r1, #0xff
    ldmneia   sp!, {r4, pc}
    ldrh r2, [r4, #0x1e]
    ldr     r1, =0xffff
    cmp r2, r1
    bne      L_0201b03c
    ldrb r0, [r4, #0x1b]
    add r0, r0, #0x1
    strb r0, [r4, #0x1b]
    ldr r0, [r4, #0x20]
    ldrh r0, [r0, #0x2]
    bl      func_0205ab44
    ldrb r2, [r4, #0x1b]
    ldrh r1, [r0, #0x6]
    cmp r2, r1
    blt      L_0201aff4
    mov r1, #0x0
    strb r1, [r4, #0x1b]
    ldr r1, [r4, #0x8]
    orr r1, r1, #0x10000
    str r1, [r4, #0x8]
    L_0201aff4:
    ldrh r2, [r0, #0x6]
    ldrb r0, [r4, #0x1b]
    sub r1, r2, #0x1
    cmp r1, r0
    cmpne r2, #0x1
    ldreq r0, [r4, #0x8]
    orreq r0, r0, #0x10000
    streq r0, [r4, #0x8]
    ldrb r0, [r4, #0x19]
    strb r0, [r4, #0x18]
    ldrb r1, [r4, #0x1a]
    ldrb r0, [r4, #0x1b]
    cmp r1, r0
    ldmeqia   sp!, {r4, pc}
    ldr r0, [r4, #0x8]
    orr r0, r0, #0x40
    str r0, [r4, #0x8]
    ldmia   sp!, {r4, pc}
    L_0201b03c:
    ldr r1, [r4, #0x8]
    and r1, r1, #0x10000
    cmp r1, #0x10000
    ldmeqia   sp!, {r4, pc}
    ldr r1, [r4, #0x24]
    add r1, r1, #0x1
    str r1, [r4, #0x24]
    bl      func_0201b07c
    ldrb r1, [r4, #0x1a]
    ldrb r0, [r4, #0x1b]
    cmp r1, r0
    ldrne r0, [r4, #0x8]
    orrne r0, r0, #0x40
    strne r0, [r4, #0x8]
    ldmia   sp!, {r4, pc}
}
// clang-format on
