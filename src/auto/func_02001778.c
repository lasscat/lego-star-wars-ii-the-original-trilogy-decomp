#include "m2c.h"

extern u32 data_020fcc68[];
extern u32 data_021019f4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02001778(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldr     r0, =data_020fcc68
    mov r3, #0x0
    stmea r4, {r0, r3}
    str r3, [r4, #0x8]
    strh r1, [r4, #0xc]
    mov r0, #0xff
    strb r0, [r4, #0xe]
    cmp r2, #0x0
    strb r3, [r4, #0xf]
    moveq r0, #0x80000000
    streq r0, [r4, #0x8]
    ldr     r1, =data_021019f4
    mov r0, #0x38
    mla r0, r2, r0, r1
    ldr r2, [r0, #0x0]
    mov r1, r4
    ldr r2, [r2, #0x8]
    blx      r2
    mov r0, r4
    ldmia   sp!, {r4, pc}
}
// clang-format on
