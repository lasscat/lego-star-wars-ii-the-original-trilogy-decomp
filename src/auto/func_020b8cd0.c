#include "m2c.h"

extern u32 data_0210daf0[];
extern void func_0205e624();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020b8cd0(s32 a0) {
    stmdb   sp!, {r4, lr}
    cmp r0, #0xff
    ldmeqia   sp!, {r4, pc}
    ldr     r1, =data_0210daf0
    mov r2, #0x24
    ldr r3, [r1, #0x0]
    mov r1, #0x0
    add r3, r3, #0x3c
    mla r4, r0, r2, r3
    mov r0, r4
    bl      func_0205e624
    mov r0, #0xff
    strb r0, [r4, #0x8]
    ldrb r0, [r4, #0x21]
    bic r2, r0, #0x3
    and r0, r2, #0xff
    bic r1, r0, #0xc
    and r0, r1, #0xff
    strb r2, [r4, #0x21]
    bic r0, r0, #0x30
    strb r0, [r4, #0x21]
    ldmia   sp!, {r4, pc}
}
// clang-format on
