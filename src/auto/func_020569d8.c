#include "m2c.h"

extern void func_02067080();
extern void func_0205e80c();
extern void func_020941bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020569d8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r5, r1
    ldrb r1, [r5, #0x0]
    ldrb r2, [r5, #0x1]
    bl      func_02067080
    movs r4, r0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    ldrb r1, [r5, #0x2]
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r0, #0x10
    mov r1, #0x0
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r1, #0x1
    str r1, [sp, #0x0]
    ldrb r3, [r5, #0x3]
    mov r1, r4
    mov r2, #0x0
    bl      func_020941bc
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
