#include "m2c.h"

extern void func_0205365c();
extern void func_0205ea38();
extern void func_0207de1c();
extern void func_0205e8d0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0207e840(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov r4, r0
    ldr r1, [r4, #0x3c]
    cmp r1, #0x0
    ldrne r0, [r1, #0x8]
    orrne r0, r0, #0x2
    strne r0, [r1, #0x8]
    ldr r0, [r4, #0x10]
    mov r1, #0x0
    bl      func_0205365c
    add r0, r4, #0x14
    mov r1, #0x0
    bl      func_0205ea38
    mov r1, #0x0
    strb r1, [r4, #0x25]
    add r0, r4, #0x14
    bl      func_0205ea38
    ldrb r1, [r4, #0x25]
    mov r0, r4
    bl      func_0207de1c
    mov r0, #0x3
    strb r0, [r4, #0x27]
    mov r1, #0x10
    add r0, r4, #0x14
    strb r1, [r4, #0x26]
    bl      func_0205e8d0
    ldmia   sp!, {r4, pc}
}
// clang-format on
