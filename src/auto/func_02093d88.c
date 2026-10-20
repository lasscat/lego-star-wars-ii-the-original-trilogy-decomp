#include "m2c.h"

extern void func_02093eac();
extern void memcpy();
extern void memset();
extern void func_02093e68();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02093d88(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x10
    mov r2, #0x0
    mov r5, r0
    str r2, [sp, #0x4]
    str r2, [sp, #0x8]
    str r2, [sp, #0xc]
    strb r2, [sp, #0x2]
    sub r0, sp, #0x4
    strb r2, [r0, #0x0]
    ldr r2, [r0, #0x0]
    add r0, sp, #0x4
    bl      func_02093eac
    ldr r4, [r5, #0x0]
    ldr r0, [r5, #0x4]
    mov ip, #0x0
    add r0, r4, r0, lsl #0x2
    sub r1, r0, r4
    mov     r0, r1, asr 0x1
    add r6, r1, r0, lsr #0x1e
    mov     r0, r6, asr 0x2
    mov     r7, r0, lsl 0x2
    ldr r3, [sp, #0x4]
    ldr r0, [sp, #0x8]
    mov r1, r4
    mov r2, r7
    add r0, r3, r0, lsl #0x2
    strb ip, [sp, #0x1]
    bl      memcpy
    mov r0, r4
    mov r2, r7
    mov r1, #0x0
    bl      memset
    ldr r1, [sp, #0x8]
    mov r0, #0x0
    add r1, r1, r6, asr #0x2
    str r1, [sp, #0x8]
    strb r0, [sp, #0x0]
    str r0, [r5, #0x4]
    add r3, sp, #0xc
    ldr r2, [r5, #0x8]
    ldr r1, [r3, #0x0]
    add r0, sp, #0x4
    str r1, [r5, #0x8]
    str r2, [r3, #0x0]
    ldr r2, [r5, #0x0]
    ldr r1, [sp, #0x4]
    str r1, [r5, #0x0]
    str r2, [sp, #0x4]
    ldr r2, [r5, #0x4]
    ldr r1, [sp, #0x8]
    str r1, [r5, #0x4]
    str r2, [sp, #0x8]
    bl      func_02093e68
    add sp, sp, #0x10
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
