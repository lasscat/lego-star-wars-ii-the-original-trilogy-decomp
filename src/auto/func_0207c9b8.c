#include "m2c.h"

extern void func_0205e8d0();
extern u32 data_027e02a4[];
extern u32 data_021019f4[];
extern void func_0200fa74();
extern void func_0200171c();
extern u32 data_027e0874[];
extern void func_020ac278();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207c9b8(s32 a0) {
    stmdb   sp!, {r3, lr}
    add r0, r0, #0xa4
    bl      func_0205e8d0
    ldr     r0, =data_027e02a4
    ldr     r2, =data_021019f4
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    bl      func_0200fa74
    ldr     r0, =data_027e02a4
    ldr     r2, =data_021019f4
    ldr r1, [r0, #0x0]
    cmp r1, #0x0
    moveq r1, #0x1
    movne r1, #0x0
    str r1, [r0, #0x0]
    ldr     r0, =data_027e02a4
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    bl      func_0200fa74
    ldr     r0, =data_027e02a4
    ldr r1, [r0, #0x0]
    cmp r1, #0x0
    moveq r1, #0x1
    movne r1, #0x0
    str r1, [r0, #0x0]
    mov r0, #0x0
    bl      func_0200171c
    ldr     r0, =data_027e0874
    mov r1, #0x4
    mov r2, #0x0
    bl      func_020ac278
    ldmia   sp!, {r3, pc}
}
// clang-format on
