#include "m2c.h"

extern void func_02067080();
extern void func_0205e80c();
extern u32 data_020ff278[];
extern u32 data_02106d90[];
extern void func_0207f56c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020568a0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r1
    ldrb r1, [r5, #0x0]
    ldrb r2, [r5, #0x1]
    bl      func_02067080
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r0, #0x10
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e80c
    movs r4, r0
    ldrne     r0, =data_020ff278
    strne r0, [r4, #0x0]
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    ldrb r2, [r5, #0x0]
    ldr     r0, =data_02106d90
    mov r1, r4
    str r2, [r4, #0x4]
    ldrb r2, [r5, #0x1]
    str r2, [r4, #0x8]
    ldrb r2, [r5, #0x2]
    strh r2, [r4, #0xc]
    ldrb r2, [r5, #0x3]
    strh r2, [r4, #0xe]
    ldr r0, [r0, #0xad8]
    bl      func_0207f56c
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
