#include "m2c.h"

extern u32 data_020f1f6c[];
extern void func_020534f4();
extern void func_0208d478();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208d41c(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r1, =data_020f1f6c
    sub r3, sp, #0x4
    ldrh r2, [r1, #0x0]
    mov r4, r0
    mov r1, #0x0
    strh r2, [r3, #0x0]
    ldr r3, [r3, #0x0]
    mov r2, #0x3
    bl      func_020534f4
    mov r0, r4
    mov r1, #0x3
    bl      func_0208d478
    ldmia   sp!, {r4, pc}
}
// clang-format on
