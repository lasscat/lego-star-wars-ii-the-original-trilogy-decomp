#include "m2c.h"

extern void func_0205365c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209c41c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    add r0, r6, #0x2c
    mov r1, #0x0
    bl      func_0205365c
    mov r5, #0x0
    mov r4, r5
    mov r7, r5
    L_0209c43c:
    add r0, r6, r5, lsl #0x2
    ldr r0, [r0, #0x90]
    cmp r0, #0x0
    beq      L_0209c458
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0209c458:
    add r0, r6, r5, lsl #0x2
    str r4, [r0, #0x90]
    ldr r0, [r0, #0xa0]
    cmp r0, #0x0
    beq      L_0209c478
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0209c478:
    add r0, r5, #0x1
    add r1, r6, r5, lsl #0x2
    and r5, r0, #0xff
    str r7, [r1, #0xa0]
    cmp r5, #0x4
    blo      L_0209c43c
    ldr r0, [r6, #0xb4]
    cmp r0, #0x0
    beq      L_0209c4a8
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0209c4a8:
    mov r0, #0x0
    str r0, [r6, #0xb4]
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
