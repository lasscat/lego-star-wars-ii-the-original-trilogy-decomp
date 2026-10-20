#include "m2c.h"

extern u32 data_0210930c[];
extern void func_02096b0c();
extern void func_020aaeb4();
extern void func_020aaa08();
extern u32 data_020ed5cc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02067838(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    mov r5, r0
    mov r6, r1
    ldr r0, [r5, #0x0]
    sub r4, r6, #0x1
    ldr r0, [r0, r4, lsl #0x3]
    cmp r0, #0x0
    ldmneia   sp!, {r4, r5, r6, pc}
    ldrb r1, [r5, #0x4]
    ldr     r0, =data_0210930c
    and r2, r6, #0xff
    bl      func_02096b0c
    cmp r0, #0x0
    ldmneia   sp!, {r4, r5, r6, pc}
    bl      func_020aaeb4
    ldrb r1, [r5, #0x4]
    and r2, r6, #0xff
    bl      func_020aaa08
    cmp r0, #0x0
    ldmneia   sp!, {r4, r5, r6, pc}
    ldr r0, [r5, #0x0]
    ldr     r1, =data_020ed5cc
    add r0, r0, r4, lsl #0x3
    ldr r0, [r0, #0x4]
    ldrb r2, [r0, #0x6]
    ldr r3, [r1, r2, lsl #0x2]
    cmp r3, #0x0
    ldmeqia   sp!, {r4, r5, r6, pc}
    add r1, r4, #0x1
    mov     r2, r1, lsl 0x10
    ldrb r1, [r5, #0x4]
    mov     r2, r2, lsr 0x10
    blx      r3
    ldr r1, [r5, #0x0]
    str r0, [r1, r4, lsl #0x3]
    ldr r0, [r5, #0x0]
    ldr r2, [r0, r4, lsl #0x3]
    cmp r2, #0x0
    ldmeqia   sp!, {r4, r5, r6, pc}
    ldrb r0, [r5, #0x4]
    add r1, r4, #0x1
    strb r0, [r2, #0x88]
    ldr r0, [r5, #0x0]
    ldr r0, [r0, r4, lsl #0x3]
    strb r1, [r0, #0x89]
    ldrb r0, [r5, #0x6]
    cmp r0, #0x0
    movne r0, #0x1
    strneb r0, [r5, #0x6]
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
