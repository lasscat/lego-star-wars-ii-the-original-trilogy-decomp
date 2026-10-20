#include "m2c.h"

extern void func_02067080();
extern void func_0205e80c();
extern u32 data_020ff2b4[];
extern u32 data_02106d90[];
extern void func_0207f56c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02056828(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    mov r6, r1
    ldrb r1, [r6, #0x2]
    ldrb r2, [r6, #0x3]
    bl      func_02067080
    movs r4, r0
    ldmeqia   sp!, {r4, r5, r6, pc}
    mov r0, #0x10
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e80c
    movs r5, r0
    ldrne     r0, =data_020ff2b4
    strne r0, [r5, #0x0]
    mov r0, r5
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    ldrh r2, [r6, #0x0]
    ldr     r0, =data_02106d90
    mov r1, r5
    strh r2, [r5, #0xc]
    str r4, [r5, #0x4]
    ldrb r2, [r6, #0x4]
    strh r2, [r5, #0xe]
    ldr r0, [r0, #0xad8]
    bl      func_0207f56c
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
