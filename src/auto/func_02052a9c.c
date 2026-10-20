#include "m2c.h"

extern void func_020accac();
extern void func_02015138();
extern void func_0201f574();
extern u32 data_0210930c[];
extern void func_0208fec8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02052a9c(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0x6c
    mov r4, r0
    ldrsh r2, [r4, #0x4]
    ldrsh r1, [r4, #0x2]
    ldrsh r0, [r4, #0x0]
    mov     r2, r2, lsl 0xc
    mov     r1, r1, lsl 0xc
    mov     r0, r0, lsl 0xc
    str r2, [sp, #0x20]
    str r0, [sp, #0x18]
    str r1, [sp, #0x1c]
    ldrh r3, [r4, #0xa]
    ldr     r2, =0xb60b60b7
    mov r5, #0x1000
    mov     r1, r3, lsl 0x10
    mov     r0, r1, lsr 0x1f
    smull r1, lr, r2, r1
    add lr, lr, r3, lsl #0x10
    mov ip, #0x0
    add lr, r0, lr, asr #0x8
    add r0, sp, #0x24
    add r1, sp, #0x18
    add r2, sp, #0x4
    add r3, sp, #0xc
    strh ip, [sp, #0x4]
    strh lr, [sp, #0x6]
    strh ip, [sp, #0x8]
    str r5, [sp, #0xc]
    str r5, [sp, #0x10]
    str r5, [sp, #0x14]
    bl      func_020accac
    ldrh r0, [r4, #0x8]
    add r2, sp, #0x24
    mov r1, #0x0
    bl      func_02015138
    ldrb r1, [r4, #0xe]
    mov r5, r0
    str r1, [sp, #0x0]
    ldrb r1, [r4, #0xd]
    ldrb r2, [r4, #0xc]
    ldrb r3, [r4, #0xf]
    bl      func_0201f574
    ldr     r0, =data_0210930c
    mov r1, r5
    ldr r0, [r0, #0x68]
    bl      func_0208fec8
    mov r0, r5
    add sp, sp, #0x6c
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
