#include "m2c.h"

extern void func_02054e58();
extern void func_020c987c();
extern void OS_Terminate();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02062fbc(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov r0, #0x1
    bl      func_02054e58
    mov r0, #0x1
    bl      func_020c987c
    mov r0, #0x1
    bl      func_020c987c
    bl      OS_Terminate
L_self:
    b       L_self
}
// clang-format on
