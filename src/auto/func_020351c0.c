#include "m2c.h"

extern void func_0205e624();
extern void func_02007f24();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020351c0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0xc
    mov r6, r0
    mov r5, r1
    mov r4, r2
    add r0, r6, #0x54
    mov r1, #0x0
    mov r2, #0x8
    bl      func_0205e624
    mov r0, #0x4
    strb r0, [r6, #0x30]
    ldr r1, [r6, #0x4]
    add r0, sp, #0x8
    ldr r3, [r1, #0x0]
    mov r2, #0x6
    ldr r3, [r3, #0x3c]
    blx      r3
    ldr r1, [sp, #0x8]
    ldr     r2, =0x3ff80000
    str r1, [r6, #0x10]
    add r0, sp, #0x0
    mov r1, #0x0
    bl      func_02007f24
    ldr r1, [r6, #0x4]
    add r0, sp, #0x4
    ldr r3, [r1, #0x0]
    mov r2, #0x6
    ldr r3, [r3, #0x3c]
    blx      r3
    add r0, sp, #0x4
    ldr r2, [r0, #0x0]
    ldr r1, [sp, #0x0]
    mov r0, #0x1
    smull r3, r1, r2, r1
    adds r2, r3, #0x800
    adc r1, r1, #0x0
    mov     r2, r2, lsr 0xc
    orr r2, r2, r1, lsl #0x14
    str r2, [r6, #0x14]
    strb r0, [r6, #0x1d]
    str r5, [r6, #0x54]
    strb r4, [r6, #0x58]
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
