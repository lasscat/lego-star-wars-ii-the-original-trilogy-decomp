#include "m2c.h"

extern void func_0205af6c();
extern void func_0205e80c();
extern void func_0205b0e8();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205b01c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r6, r2
    add r0, sp, #0x0
    add r2, sp, #0x1c
    mov r1, r7
    mov r5, r3
    bl      func_0205af6c
    ldr r1, [sp, #0x0]
    add r0, r7, #0x4
    cmp r1, r0
    ldmnefd   sp!, {r3, r4, r5, r6, r7, lr}
    addne sp, sp, #0x10
    bxne lr
    mov r0, #0xc
    mov r1, #0x0
    mov r2, #0x4
    bl      func_0205e80c
    mov r4, r0
    mov r0, #0x10000
    ldr r2, [r4, #0x8]
    rsb r0, r0, #0x0
    and r2, r2, r0
    ldrh r1, [sp, #0x1c]
    mov     r0, r6, lsl 0x1f
    cmp r6, #0x0
    orr r3, r2, r1
    bic r1, r3, #0x800000
    orr r2, r1, r0, lsr #0x8
    bic r1, r2, #0x1000000
    mov     r0, r5, lsl 0x1f
    orr r1, r1, r0, lsr #0x7
    str r1, [r4, #0x8]
    ldr r0, [sp, #0x28]
    add r1, sp, #0x1c
    str r0, [r4, #0x0]
    mov r0, #0x0
    str r0, [r4, #0x4]
    ldr r0, [r4, #0x8]
    bicne r0, r0, #0x7f0000
    orrne r0, r0, #0x10000
    biceq r0, r0, #0x7f0000
    orreq r0, r0, #0xa0000
    str r0, [r4, #0x8]
    mov r0, r7
    bl      func_0205b0e8
    str r4, [r0, #0x4]
    ldmfd   sp!, {r3, r4, r5, r6, r7, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
