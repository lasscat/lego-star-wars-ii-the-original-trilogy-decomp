#include "m2c.h"

extern void func_0205e80c();
extern u32 data_020fd114[];
extern u32 data_020fd128[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201c478(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldr r0, [r4, #0x80]
    cmp r0, #0x0
    beq      L_0201c4b4
    ldr r1, [r0, #0x4]
    subs r1, r1, #0x1
    str r1, [r0, #0x4]
    bne      L_0201c4b4
    cmp r0, #0x0
    beq      L_0201c4b4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0201c4b4:
    mov r0, #0x18
    mov r1, #0x0
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    beq      L_0201c504
    ldr     r1, =data_020fd114
    mov r2, #0x1
    str r1, [r0, #0x0]
    ldr     r1, =data_020fd128
    str r2, [r0, #0x4]
    ldr r2, [sp, #0xc]
    str r1, [r0, #0x0]
    ldr r1, [sp, #0x10]
    str r2, [r0, #0x8]
    ldr r2, [sp, #0x14]
    str r1, [r0, #0xc]
    ldr r1, [sp, #0x18]
    str r2, [r0, #0x10]
    str r1, [r0, #0x14]
    L_0201c504:
    str r0, [r4, #0x80]
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
