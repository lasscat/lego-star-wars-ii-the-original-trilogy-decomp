#include "m2c.h"

extern void func_02011384();
extern u32 data_020fd2c8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201dbdc(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r0
    mov r5, r3
    bl      func_02011384
    ldr     r0, =data_020fd2c8
    add r1, r4, #0x200
    str r0, [r4, #0x0]
    ldrh r3, [r5, #0x3e]
    mov r2, #0x0
    mov r0, r4
    strh r3, [r1, #0x20]
    strh r2, [r1, #0x22]
    strh r2, [r1, #0x24]
    strb r2, [r4, #0x1bc]
    ldr r2, [r4, #0xdc]
    ldrh r1, [r2, #0xe]
    add r1, r2, r1
    ldr r1, [r1, #0xc]
    add r1, r2, r1
    add r3, r1, #0x40
    ldrh r2, [r3, #0x6]
    ldrh r1, [r3, r2]
    add r2, r3, r2
    add r1, r2, r1, lsl #0x1
    ldr r1, [r1, #0x4]
    add r1, r3, r1
    str r1, [r4, #0x218]
    add r1, r1, #0x10
    str r1, [r4, #0x21c]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
