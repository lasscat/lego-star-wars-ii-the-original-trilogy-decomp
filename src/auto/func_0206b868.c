#include "m2c.h"

extern void func_02053c98();
extern void func_02053b50();
extern void func_0205ab58();
extern void func_0205e6e0();
extern void func_02055b04();
extern void func_02055b24();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206b868(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    mov r5, r1
    add r4, r6, r5, lsl #0x5
    ldrh r7, [r4, #0x16]
    add r0, r4, #0xc
    mov r2, #0x0
    mov r1, r7
    bl      func_02053c98
    add r0, r4, #0xc
    bl      func_02053b50
    mov r4, r0
    ldr     r0, =0x1465
    bl      func_0205ab58
    add r1, r7, #0x1
    mov     r1, r1, lsl 0x10
    mov     r1, r1, lsr 0xb
    add r1, r1, r1, lsr #0x1f
    mov     r2, r1, asr 0x1
    mov r1, r0
    add r0, r4, r2, lsl #0x1
    mov r2, #0x6c0
    bl      func_0205e6e0
    ldr     r0, =0x1466
    add r1, r6, r5, lsl #0x5
    ldrh r1, [r1, #0x14]
    mov r2, #0x10
    mov r3, r5
    mov     r1, r1, lsl 0x4
    bl      func_02055b04
    ldr     r0, =0x1466
    add r1, r6, r5, lsl #0x5
    ldrh r1, [r1, #0x14]
    mov r2, #0x10
    mov r3, r5
    add r1, r1, #0x1
    mov     r1, r1, lsl 0x4
    bl      func_02055b04
    add r0, r6, r5, lsl #0x5
    str r5, [sp, #0x0]
    ldrh r2, [r0, #0x14]
    ldr     r0, =0x8f9
    mov r1, #0x24
    mov     r2, r2, lsl 0x4
    add r2, r2, #0x1
    mov r3, #0x3
    bl      func_02055b24
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
