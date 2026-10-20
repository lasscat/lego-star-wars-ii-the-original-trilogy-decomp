#include "m2c.h"

extern void func_020acae8();
extern u32 data_020ffbb8[];
extern void func_0209f19c();
extern void func_0209f180();
extern void func_020e46bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209f404(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    bl      func_020acae8
    ldr     r0, =data_020ffbb8
    ldr     ip, =func_0209f19c
    str r0, [r4, #0x0]
    ldr     r3, =func_0209f180
    add r0, r4, #0x74
    mov r1, #0x5
    mov r2, #0x8
    str ip, [sp, #0x0]
    bl      func_020e46bc
    mov r1, #0x0
    str r1, [r4, #0x9c]
    str r1, [r4, #0xa0]
    mov r0, #0x1000
    str r0, [r4, #0xa4]
    ldr     r0, =0x276
    str r1, [r4, #0xa8]
    strh r0, [r4, #0xac]
    mov r0, #0xf5
    strh r0, [r4, #0xae]
    strb r1, [r4, #0xb0]
    strb r1, [r4, #0xb1]
    str r1, [r4, #0xb4]
    str r1, [r4, #0xb8]
    orr r1, r1, #0x2
    mov r0, r4
    strh r1, [r4, #0xb2]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
