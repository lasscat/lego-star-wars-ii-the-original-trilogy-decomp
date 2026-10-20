#include "m2c.h"

extern void func_020accac();
extern void func_02015138();
extern void func_02015dcc();
extern u32 data_021098d0[];
extern void func_02083cd8();
extern u32 data_0210930c[];
extern void func_0208fec8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02050e2c(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x70
    mov r6, r0
    ldrsh r4, [r6, #0x4]
    ldrsh r3, [r6, #0x2]
    ldrsh r0, [r6, #0x0]
    mov     r4, r4, lsl 0xc
    mov     r3, r3, lsl 0xc
    mov     r0, r0, lsl 0xc
    str r4, [sp, #0x24]
    str r0, [sp, #0x1c]
    str r3, [sp, #0x20]
    ldrh lr, [r6, #0xa]
    ldr     r4, =0xb60b60b7
    mov r7, #0x1000
    mov     r8, lr, lsl 0x10
    smull r0, r3, r4, r8
    mov ip, #0x0
    mov r5, r1
    mov r4, r2
    add r3, r3, lr, lsl #0x10
    mov     r0, r8, lsr 0x1f
    add r3, r0, r3, asr #0x8
    strh r3, [sp, #0xa]
    add r0, sp, #0x28
    add r1, sp, #0x1c
    add r2, sp, #0x8
    add r3, sp, #0x10
    strh ip, [sp, #0x8]
    strh ip, [sp, #0xc]
    str r7, [sp, #0x10]
    str r7, [sp, #0x14]
    str r7, [sp, #0x18]
    bl      func_020accac
    ldrh r0, [r6, #0x8]
    add r2, sp, #0x28
    mov r1, #0x0
    bl      func_02015138
    ldrb r1, [r6, #0xf]
    mov r7, r0
    str r1, [sp, #0x0]
    ldrb r1, [r6, #0x10]
    str r1, [sp, #0x4]
    ldrb r1, [r6, #0xd]
    ldrb r2, [r6, #0xc]
    ldrb r3, [r6, #0xe]
    bl      func_02015dcc
    ldr     r0, =data_021098d0
    mov r2, r5
    mov r3, r4
    mov r1, r7
    bl      func_02083cd8
    ldr     r0, =data_0210930c
    mov r1, r7
    ldr r0, [r0, #0x68]
    bl      func_0208fec8
    mov r0, r7
    add sp, sp, #0x70
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
