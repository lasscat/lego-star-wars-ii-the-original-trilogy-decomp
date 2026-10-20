#include "m2c.h"

extern void func_02091e30();
extern void func_020b95bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020927f0(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldr r2, [r4, #0x928]
    ldrb r0, [r2, #0x40]
    ldrb r3, [r2, #0x5da]
    cmp r0, #0x0
    ldrne r1, [r2, #0x8]
    andne r0, r1, #0x2
    cmpne r0, #0x2
    andne r0, r1, #0x800
    cmpne r0, #0x800
    ldmeqia   sp!, {r4, pc}
    and r0, r1, #0x1
    cmp r0, #0x1
    ldmneia   sp!, {r4, pc}
    ldrb r1, [r4, #0x92d]
    cmp r3, r1
    ldmeqia   sp!, {r4, pc}
    add r0, r4, r1, lsl #0x2
    ldr ip, [r0, #0x4c]
    ldr     r0, =0x803
    ldr r3, [ip, #0x8]
    and r0, r3, r0
    cmp r0, #0x1
    moveq r3, #0x1
    ldrb r0, [ip, #0x40]
    movne r3, #0x0
    tst r3, r0
    movne r0, #0x1
    moveq r0, #0x0
    cmp r0, #0x0
    ldmeqia   sp!, {r4, pc}
    mov r0, r4
    bl      func_02091e30
    ldrb r0, [r4, #0x92d]
    add r0, r4, r0, lsl #0x2
    ldr r1, [r0, #0x4c]
    cmp r1, #0x0
    ldmeqia   sp!, {r4, pc}
    mov r0, #0xa8
    bl      func_020b95bc
    ldmia   sp!, {r4, pc}
}
// clang-format on
