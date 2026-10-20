#include "m2c.h"

extern void func_020accac();
extern void func_02015138();
extern void func_020243d4();
extern u32 data_0210930c[];
extern void func_0208fec8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02052b6c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x68
    mov r4, r0
    ldrsh r2, [r4, #0x4]
    ldrsh r1, [r4, #0x2]
    ldrsh r0, [r4, #0x0]
    mov     r2, r2, lsl 0xc
    mov     r1, r1, lsl 0xc
    mov     r0, r0, lsl 0xc
    str r2, [sp, #0x1c]
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    ldrh r3, [r4, #0xa]
    ldr     r2, =0xb60b60b7
    mov ip, #0x1000
    mov     r1, r3, lsl 0x10
    mov     r0, r1, lsr 0x1f
    smull r1, r5, r2, r1
    add r5, r5, r3, lsl #0x10
    mov lr, #0x0
    add r5, r0, r5, asr #0x8
    add r0, sp, #0x20
    add r1, sp, #0x14
    add r2, sp, #0x0
    add r3, sp, #0x8
    strh lr, [sp, #0x0]
    strh r5, [sp, #0x2]
    strh lr, [sp, #0x4]
    str ip, [sp, #0x8]
    str ip, [sp, #0xc]
    str ip, [sp, #0x10]
    bl      func_020accac
    ldrh r0, [r4, #0x8]
    add r2, sp, #0x20
    mov r1, #0x0
    bl      func_02015138
    ldrsb r1, [r4, #0xc]
    mov r4, r0
    bl      func_020243d4
    ldr     r0, =data_0210930c
    mov r1, r4
    ldr r0, [r0, #0x68]
    bl      func_0208fec8
    mov r0, r4
    add sp, sp, #0x68
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
