#include "m2c.h"

extern u32 data_027e02a4[];
extern u32 data_021019f4[];
extern void func_0208355c();
extern u32 data_0210930c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020834e0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r1, =data_027e02a4
    ldr     r2, =data_021019f4
    ldr r3, [r1, #0x0]
    mov r1, #0x38
    mla r1, r3, r1, r2
    ldr r4, [r1, #0x4]
    mov r5, r0
    cmp r4, #0x0
    beq      L_02083520
    L_02083508:
    ldr r1, [r4, #0x0]
    mov r0, r5
    bl      func_0208355c
    ldr r4, [r4, #0x4]
    cmp r4, #0x0
    bne      L_02083508
    L_02083520:
    ldr     r0, =data_0210930c
    ldr r0, [r0, #0x68]
    ldr r4, [r0, #0x394]
    cmp r4, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    L_02083534:
    ldr r1, [r4, #0x0]
    mov r0, r5
    bl      func_0208355c
    ldr r4, [r4, #0x4]
    cmp r4, #0x0
    bne      L_02083534
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
