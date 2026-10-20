#include "m2c.h"

extern u32 data_02101ae4[];
extern u32 data_020e5d08[];
extern void func_0205ab6c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020185b4(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr     r0, =data_02101ae4
    ldrb ip, [r5, #0x6]
    ldr r3, [r0, #0x0]
    ldr     r4, =data_020e5d08
    mov r2, #0x6
    ldr r3, [r3, #0xc]
    mov r1, r5
    mla r4, ip, r2, r4
    blx      r3
    ldr r2, [r5, #0x0]
    mov r0, #0x0
    ldr r1, [r2, #0x384]
    orr r1, r1, #0x80000000
    str r1, [r2, #0x384]
    str r0, [r5, #0x0]
    ldrh r0, [r4, #0x2]
    bl      func_0205ab6c
    mov r0, r5
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
