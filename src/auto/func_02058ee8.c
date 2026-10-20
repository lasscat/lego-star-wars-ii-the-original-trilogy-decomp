#include "m2c.h"

extern void func_02067080();
extern void func_0202c01c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02058ee8(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r2, r1
    ldrb r1, [r2, #0x0]
    ldrb r2, [r2, #0x1]
    bl      func_02067080
    movs r1, r0
    ldmeqia   sp!, {r3, pc}
    add r0, r1, #0x5e0
    bl      func_0202c01c
    ldmia   sp!, {r3, pc}
}
// clang-format on
